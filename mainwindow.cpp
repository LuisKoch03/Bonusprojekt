#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kartenstapel.h"

#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>


KartenStapel stapel;
int wette = 0;
Karte karte1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clicks(0)
    , clicksPerClick(1)
    , clicksPerSecond(0)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCounter);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clickMich_clicked()
{
    clicks = clicks + clicksPerClick;
    ui->clicks->setText(QString::number(clicks));
}


void MainWindow::on_extraClickKauf_clicked()
{
    int extraClickPreis = ui->extraClickPreis->text().toInt();
    int extraClickBesitz = ui->extraClickBesitz->text().toInt();
    if(clicks >= extraClickPreis)
    {
        clicks = clicks - extraClickPreis;
        clicksPerClick++;
        ui->clicksProClick->setText(QString::number(clicksPerClick));
        extraClickBesitz++;
        extraClickPreis = extraClickPreis * 2;
        ui->extraClickPreis->setText(QString::number(extraClickPreis));
        ui->extraClickBesitz->setText(QString::number(extraClickBesitz));
        ui->clicks->setText(QString::number(clicks));
    }
}


void MainWindow::on_autoClickKauf_clicked()
{
    int autoClickPreis = ui->autoClickPreis->text().toInt();
    int autoClickBesitz = ui->autoClickBesitz->text().toInt();
    if(clicks >= autoClickPreis)
    {
        clicks = clicks - autoClickPreis;
        clicksPerSecond++;
        ui->clicksProSek->setText(QString::number(clicksPerSecond));
        autoClickBesitz++;
        autoClickPreis = autoClickPreis * 2;
        ui->autoClickPreis->setText(QString::number(autoClickPreis));
        ui->autoClickBesitz->setText(QString::number(autoClickBesitz));
        ui->clicks->setText(QString::number(clicks));
    }
}

void MainWindow::updateCounter()
{
    clicks = clicks + clicksPerSecond;
    ui->clicks->setText(QString::number(clicks));
    if (clicks >= ui->extraClickPreis->text().toInt())
    {
        ui->extraClickKauf->setStyleSheet("background-color : #90EE90");
    }

    else
    {
        ui->extraClickKauf->setStyleSheet("background-color : #FF6347");
    }

    if (clicks >= ui->autoClickPreis->text().toInt())
    {
        ui->autoClickKauf->setStyleSheet("background-color : #90EE90");
    }
    else
    {
        ui->autoClickKauf->setStyleSheet("background-color : #FF6347");
    }

    if (clicks >= ui->autoClickPreis_2->text().toInt())
    {
        ui->autoClickKauf_2->setStyleSheet("background-color : #90EE90");
    }
    else
    {
        ui->autoClickKauf_2->setStyleSheet("background-color : #FF6347");
    }
}

void MainWindow::on_wetteStart_clicked()
{
    ui->karte1->setText(NULL);
    ui->karte2->setText(NULL);
    try {
        string wettString = ui->wettBetrag->text().toStdString();
        wette = stoi(wettString);

        if (wette <= 0) {
            throw invalid_argument("");
        }
        if (wette >= clicks + 1)
        {
            throw out_of_range("");
        }

        karte1 = stapel.zieheKarte();
        QString wertString = QString::number(karte1.getWert());
        QString farbeString = QString::fromStdString(karte1.getFarbe());
        QString text = wertString + ", " + farbeString;
        ui->karte1->setText(text);
    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Ungültige Eingabe", "Nur Positive Zahlen eingeben");
    } catch (const std::out_of_range& e) {
        QMessageBox::warning(this, "Ungültige Eingabe", "Du hast nicht so viele Clicks");
    }
}


void MainWindow::on_hoeher_clicked()
{
    if (wette != 0)
    {
        Karte karte2 = stapel.zieheKarte();
        QString wertString = QString::number(karte2.getWert());
        QString farbeString = QString::fromStdString(karte2.getFarbe());
        QString text2 = wertString + ", " + farbeString;
        ui->karte2->setText(text2);
        if (karte1.getWert() < karte2.getWert())
        {
            ui->ergebniss->setText("Gewonnen");
            clicks = clicks + wette;
        }
        else if (karte1.getWert() > karte2.getWert())
        {
            ui->ergebniss->setText("Verloren");
            clicks = clicks - wette;
        }
        else
        {
            ui->ergebniss->setText("Unentschieden");
        }
        wette = 0;
        ui->wettBetrag->setText(NULL);
    }

}


void MainWindow::on_niedriger_clicked()
{
    if (wette != 0)
    {
        Karte karte2 = stapel.zieheKarte();
        QString wertString = QString::number(karte2.getWert());
        QString farbeString = QString::fromStdString(karte2.getFarbe());
        QString text2 = wertString + ", " + farbeString;
        ui->karte2->setText(text2);
        if (karte1.getWert() > karte2.getWert())
        {
            ui->ergebniss->setText("Gewonnen");
            clicks = clicks + wette;
        }
        else if (karte1.getWert() < karte2.getWert())
        {
            ui->ergebniss->setText("Verloren");
            clicks = clicks - wette;
        }
        else
        {
            ui->ergebniss->setText("Unentschieden");
        }
        wette = 0;
        ui->wettBetrag->setText(NULL);
    }
}


void MainWindow::on_spielLaden_clicked()
{
    QString filter = "Textdateien (*.txt);;Alle Dateien (*.*)";
    QString file = QFileDialog::getOpenFileName(this, "Datei auswählen", QDir::homePath(), filter);

    if (!file.isEmpty()) {

        qDebug() << "Ausgewählte Datei: " << file;
    } else {
        qDebug() << "Keine Datei ausgewählt.";
    }
}


void MainWindow::on_spielSpeichern_2_clicked()
{
    QString filter = "Textdateien (*.txt)";
    QString speicherName = "Save_";
    QDateTime uhrzeit = QDateTime::currentDateTime();
    QString uhrzeitStr = uhrzeit.toString("yyyyMMdd_hhmmss");
    speicherName += uhrzeitStr + ".txt";

    QString filePath = QFileDialog::getSaveFileName(this, "Datei speichern", QDir::homePath(), filter, &speicherName);

    if (!filePath.isEmpty()) {
        // Hier kannst du die Datei speichern oder mit dem Dateipfad 'filePath' weiterarbeiten
        qDebug() << "Gespeichert unter: " << filePath;
    } else {
        // Wenn der Benutzer den Dialog geschlossen oder abgebrochen hat
        qDebug() << "Speichern abgebrochen.";
    }
}


void MainWindow::on_autoClickKauf_2_clicked()
{
    int autoClickPreis = ui->autoClickPreis_2->text().toInt();
    int autoClickBesitz = ui->autoClickBesitz_2->text().toInt();
    if(clicks >= autoClickPreis)
    {
        clicks = clicks - autoClickPreis;
        clicksPerSecond += 5;
        ui->clicksProSek->setText(QString::number(clicksPerSecond));
        autoClickBesitz++;
        autoClickPreis = autoClickPreis * 2;
        ui->autoClickPreis_2->setText(QString::number(autoClickPreis));
        ui->autoClickBesitz_2->setText(QString::number(autoClickBesitz));
        ui->clicks->setText(QString::number(clicks));
    }
}


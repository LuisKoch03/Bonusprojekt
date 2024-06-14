#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

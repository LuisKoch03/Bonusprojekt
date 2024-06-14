#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int clicks = 0;
int clicksPerClick = 1;


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


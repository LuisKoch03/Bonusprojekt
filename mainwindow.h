#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clickMich_clicked();

    void on_extraClickKauf_clicked();

    void on_autoClickKauf_clicked();

    void on_wetteStart_clicked();

    void on_hoeher_clicked();

    void on_niedriger_clicked();

    void on_spielLaden_clicked();

    void on_spielSpeichern_2_clicked();

    void on_autoClickKauf_2_clicked();

private:
    Ui::MainWindow *ui;
    void updateCounter();
    QTimer *timer;
    int clicks;
    int clicksPerClick;
    int clicksPerSecond;
};
#endif // MAINWINDOW_H

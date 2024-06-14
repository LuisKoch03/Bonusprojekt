#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QLabel>

class MyWidget : public QWidget{
public:
    MyWidget(QWidget *parent = NULL) : QWidget(parent) {
        this->resize(320, 240);
        this->setWindowTitle("Hallo Welt mit Qt");
        QLabel* label = new QLabel("Hallo Welt", this);
    }
};

#endif // MYWIDGET_H

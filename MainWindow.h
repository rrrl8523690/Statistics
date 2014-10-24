#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "input.h"

class MainWindow:public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent);
private:
    QHBoxLayout *mainLayout;
    QVBoxLayout *answerLayout;
    QGridLayout *sampleInputLayout;
    QLineEdit *lineEditN;

    const int sampleInputColumns = 5;

    Input *inputN, *inputAverage, *inputVariance, *inputModifiedVariance;

private slots:
    void refreshSampleInputs(QString n);
    void caculate();
};

#endif // MAINWINDOW_H

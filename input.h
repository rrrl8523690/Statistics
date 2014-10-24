#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include <QtWidgets>

class Input : public QWidget
{
    Q_OBJECT
public:
    QLineEdit *lineEdit;
    explicit Input(QString prompt, QWidget *parent = 0);

signals:
    void valueChanged(QString string);
public slots:

};

#endif // INPUT_H

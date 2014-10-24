#include "input.h"

Input::Input(QString prompt, QWidget *parent) :
    QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel(prompt));
    lineEdit = new QLineEdit(this);

    layout->addWidget(lineEdit);
    this->setLayout(layout);

    connect(lineEdit, SIGNAL(textChanged(QString)),
            this, SIGNAL(valueChanged(QString)));

//    this->setSizePolicy(QSizePolicy);
//    resize(QSize(100, 100));
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

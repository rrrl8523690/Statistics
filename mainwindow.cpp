#include "MainWindow.h"
#include "input.h"

MainWindow::MainWindow(QWidget *parent = NULL)
    :QWidget(parent) {
    mainLayout = new QHBoxLayout(this);
    answerLayout = new QVBoxLayout(this);
    sampleInputLayout = new QGridLayout(this);

    inputN = new Input(tr("Sample Size"), this);
    inputAverage = new Input(tr("Sample Average"), this);
    inputVariance = new Input(tr("Sample Variance"), this);
    inputModifiedVariance = new Input(tr("Modified Sample Variance"), this);

    inputAverage->lineEdit->setReadOnly(true);
    inputVariance->lineEdit->setReadOnly(true);
    inputModifiedVariance->lineEdit->setReadOnly(true);

    answerLayout->addWidget(inputN);
    answerLayout->addWidget(inputAverage);
    answerLayout->addWidget(inputVariance);
    answerLayout->addWidget(inputModifiedVariance);


//    sampleInputLayout->setContentsMargins(10, 10, 10, 10);

//    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addLayout(answerLayout);
    mainLayout->addLayout(sampleInputLayout);


    this->setLayout(mainLayout);

    connect(inputN, SIGNAL(valueChanged(QString)), this, SLOT(refreshSampleInputs(QString)));
}

void MainWindow::refreshSampleInputs(QString stringN) {
    int n = stringN.toInt();
    if (0 == n) {
        return ;
    }
    int i;

    while (sampleInputLayout->count() > n) {
        delete sampleInputLayout->itemAt(n)->widget();
    }
    for (i = sampleInputLayout->count(); i < n; i++) {
        QString prompt = QString("样本") + QString().setNum(i);
        Input *input;
        input = new Input(prompt, this);
        sampleInputLayout->addWidget(input, i / sampleInputColumns, i % sampleInputColumns);
        connect(input, SIGNAL(valueChanged(QString)), this, SLOT(caculate()));
    }
}

void MainWindow::caculate() {
    int i, n = inputN->lineEdit->text().toInt();
    double sum, average, sampleVariance, modifiedSampleVariance;
    sum = 0;
    double *x = new double[sampleInputLayout->count()];
    Input *input;
    for (i = 0; i < sampleInputLayout->count(); i++) {
        input = (Input*) sampleInputLayout->itemAt(i)->widget();
        x[i] = input->lineEdit->text().toDouble();
    }
    for (i = 0; i < n; i++) {
        sum += x[i];
    }
    average = sum / n;
    sum = 0;
    for (i = 0; i < n; i++) {
        sum += (average - x[i]) * (average - x[i]);
    }
    sampleVariance = sum / n;
    if (!n)
        modifiedSampleVariance = 0;
    else
        modifiedSampleVariance = sum / (n - 1);

    inputAverage->lineEdit->setText(QString().setNum(average));
    inputVariance->lineEdit->setText(QString().setNum(sampleVariance));
    inputModifiedVariance->lineEdit->setText(QString().setNum(modifiedSampleVariance));
    delete x;
}

// 18911938035

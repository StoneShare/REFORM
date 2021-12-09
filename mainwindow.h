#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "DataForm.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(){
        QWidget *basic = new QWidget;

        QHBoxLayout *hbasic = new QHBoxLayout(basic);
        GenerationData *ofData = new GenerationData("Исходные:",true);
        ofData->table->setDefaultData();
        GenerationData *toData = new GenerationData("Результат:");
        hbasic->addWidget(ofData);
        hbasic->addWidget(toData);

        /* сигналы слоты изменения данными */
        connect(ofData->table,&TableForm::pushCalc,toData->table,&TableForm::calcData);

        /* кнопки управления */
        QPushButton *calc = new QPushButton("Рассчитать");
        connect(calc,&QPushButton::clicked,ofData->table,&TableForm::updateForm);

        QGroupBox *group = new QGroupBox("Управление");
        QVBoxLayout *vlay = new QVBoxLayout(group);
        vlay->addWidget(calc);
        hbasic->addWidget(group);

        setCentralWidget(basic);
    }
    ~MainWindow(){}
};
#endif // MAINWINDOW_H

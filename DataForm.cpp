#include "DataForm.h"
#include "DataForm.h"

TableForm::TableForm(bool calculated){
    type = calculated;
    verticalHeader()->hide();
    horizontalHeader()->hide();
}

void TableForm::setDefaultData(){
    data = {{0,2,3,9,7},
            {6,2,4,5,8},
            {8,9,1,2,8},
            {6,5,4,3,0},
            {9,7,6,2,1}};
    updateForm();
}

void TableForm::generateData(){
    updateForm();
}

void TableForm::saveData(){}

void TableForm::updateForm(){
    if(data.size()>0){
        int wSize = (int)data.size();
        int hSize = (int)data.front().size();
        if(wSize>columnCount()){
            setColumnCount(wSize);
        }
        if(hSize>rowCount()){
            setRowCount(hSize);
        }
        /* заполнение таблицы данными */
        for(int r=0; r<hSize; r++){
            for(int c=0; c<wSize; c++){
                QTableWidgetItem *item = new QTableWidgetItem(QVariant(data[r][c]).toString());
                setItem(r,c,item);
            }
        }
        resizeColumnsToContents();
        resizeRowsToContents();

        type?emit pushCalc(data):void();
    }
}

GenerationData::GenerationData(QString head, bool calculated){
    table = new TableForm(calculated);

    QHBoxLayout *hlay = new QHBoxLayout(this);

    /* расположение объектов на форме */
    QGroupBox *group = new QGroupBox;
    QVBoxLayout *_vlay = new QVBoxLayout(group);
    _vlay->addWidget(new QLabel(head));
    _vlay->addWidget(table);

    hlay->addWidget(group);
}

GenerationData::~GenerationData(){
    delete table;
}

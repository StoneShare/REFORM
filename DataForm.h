#ifndef DATAFORM_H
#define DATAFORM_H

#include <QObject>
#include <QWidget>
#include <QMetaType>

#include <QLabel>
#include <QGroupBox>
#include <QTableWidget>
#include <QHeaderView>

#include <QVBoxLayout>
#include <QFormLayout>

#include <string>
#include <stdlib.h>

using namespace std;
/* таблица отображения данных */
class TableForm : public QTableWidget{
    Q_OBJECT
public: signals:
    void pushCalc(vector<vector<int>> data);
private:
    vector<vector<int>> data;
    bool type;
public:
    TableForm(bool calculated = false);
    ~TableForm(){}

    void setDefaultData();//установка данных из примера
    void generateData();//генерация новых данных
    void saveData();//сохранение данных в историю
public slots:
    void calcData(vector<vector<int>> data){
        if((int)data.front().size()>0)
            this->data = reCalcData(data);
        updateForm();
    }//расчет данных в результирующую таблицу
    void updateForm();//обновление формы
private:
    vector<vector<int>> reCalcData(vector<vector<int>> data){
        vector<vector<int>> rematrix;
        for(int r=0; r<(int)data.size(); r++){
            for(int c=0; c<(int)data[r].size(); c++){

            }
        }
        /* Если в строке встречаются одинаковые числа, то они заменяются на результат произведения этого числа на количество повторений.
           Если повторения встречаются только в строке, то подсвечивать число желтым цветом; */

        /* Если в столбце встречаются одинаковые числа, то они заменяются на результат произведения этого числа на количество повторений.
           Если повторения встречаются тольков столбце, то подсвечивать число зеленым цветом; */

        /* Если число встречается и в строке, и в столбце, то оно заменяется на сумму произведения этого числа на количество повторений
           в строке и произведения этого числа на количество повторений в столбце. Число подсвечивать синим цветом; */

        /* Если число встречает в строке и столбце один раз, то оно переносится без изменений. */

        return rematrix;
    }
//    vector<int> rowMaker(vector<int> data, int pos=0, int value=0, int count=0, vector<int> counter=vector<int>()){
//        if(pos <= (int)data.size()){
//            if (count>0){
//                /* умножение строки на количество повторений */
//                for(int i=0; i<(int)counter.size(); i++){
//                    data[i] = data[i]*count;
//                }
//                value = data[pos];
//            }
//            if(count == 0){
//                for(int i=0; i<(int)data.size(); i++){
//                    if(data[i] == value){
//                        count++;
//                        counter.push_back(i);
//                    }
//                }
//                pos++;
//                rowMaker(data,pos,data[pos],0,counter);
//            }
//        }else{
//            return data;
//        }
//        return data;
//    }
//        if (pos < s.Length) // пока не последний символ S[pos] - осуществляются рекурсивные вызовы
//        {
//          if (pos == 0) // первый символ строки
//            // перейти к обработке следующего символа
//            return ConvertStr(s, pos + 1, s[pos], 1, s2);
//          else // не первый символ строки
//          {
//            if (s[pos] == c) // если следующий и предыдущий символы совпадают, то движемся дальше
//              return ConvertStr(s, pos + 1, s[pos], k + 1, s2);
//            else // если символы отличаются, то зафиксировать в строке s2 временный результат
//            {
//              // если k==1, то просто добавить к s2 символ c,
//              // иначе, перед символом c поставить число k
//              if (k == 1)
//                s2 = s2 + c.ToString();
//              else
//                s2 = s2 + k.ToString() + c.ToString(); // s2 = s2 + "AAA' = s2 + "3A"
//              // перейти на следующий уровень рекурсии, продолжить обработку строки
//              return ConvertStr(s, pos + 1, s[pos], 1, s2);
//            }
//          }
//        }
//        else // пройдена вся строка
//        {
//          // завершить обработку строки
//          if (k == 1)
//            s2 = s2 + c.ToString();
//          else
//            s2 = s2 + k.ToString() + c.ToString();
//          return s2; // окончание рекурсивного процесса
//    }
};

/* форма генерации данных */
class GenerationData: public QWidget{
    Q_OBJECT
public:
    TableForm *table;
private:
    bool type;
public:
    GenerationData(QString head, bool calculated = false);
    ~GenerationData();
};

#endif // DATAFORM_H

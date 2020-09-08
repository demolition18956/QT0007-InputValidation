#include "beepintvalidator.h"
#include <QApplication>

BeepIntValidator::BeepIntValidator(QObject* parent)
    : QIntValidator(parent)
{

}

BeepIntValidator::BeepIntValidator(int minimum, int maximum, QObject* parent)
    : QIntValidator(minimum,maximum,parent)
{

}

QValidator::State BeepIntValidator::validate(QString &input, int &pos) const
{
    QValidator::State state = QIntValidator::validate(input,pos);
    if (state == QValidator::Invalid){
        QApplication::beep();
    }
    return state;
}

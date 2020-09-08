#include "dialog.h"
#include "ui_dialog.h"
#include "beepintvalidator.h"
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QDoubleValidator>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    BeepIntValidator* intValidator = new BeepIntValidator(ui->intLineEdit);
    ui->intLineEdit->setValidator(intValidator);

    BeepIntValidator* byteIntValidator = new BeepIntValidator(0,255,ui->intSmallLineEdit);
    ui->intSmallLineEdit->setValidator(byteIntValidator);

    QRegularExpressionValidator* binaryValidator = new QRegularExpressionValidator(QRegularExpression("[01]{1,8}"),ui->binLineEdit);
    ui->binLineEdit->setValidator(binaryValidator);

    QRegularExpressionValidator* hexValidator = new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{1,2}"),ui->hexLineEdit);
    ui->hexLineEdit->setValidator(hexValidator);

    QDoubleValidator* floatValidator = new QDoubleValidator(-1000.0,1000.0,1,ui->floatLineEdit);
    ui->floatLineEdit->setValidator(floatValidator);

    QRegularExpressionValidator* lowerValidator = new QRegularExpressionValidator(QRegularExpression("[a-z]{1,15}"),ui->lowerLineEdit);
    ui->lowerLineEdit->setValidator(lowerValidator);

    QRegularExpressionValidator* upOrLowValidator = new QRegularExpressionValidator(QRegularExpression("[A-Za-z]{1,15}"),ui->upOrLowLineEdit);
    ui->upOrLowLineEdit->setValidator(upOrLowValidator);

    QRegularExpressionValidator* phoneValidator = new QRegularExpressionValidator(QRegularExpression("[0-9]{3}-[0-9]{3}-[0-9]{4}"),ui->phoneLineEdit);
    ui->phoneLineEdit->setValidator(phoneValidator);
}

Dialog::~Dialog()
{
    delete ui;
}

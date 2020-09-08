#include <QIntValidator>
#ifndef BEEPINTVALIDATOR_H
#define BEEPINTVALIDATOR_H


class BeepIntValidator : public QIntValidator
{
public:
    BeepIntValidator(QObject* parent = nullptr);
    BeepIntValidator(int minimum, int maximum, QObject* parent);

    QValidator::State validate(QString& input, int& pos) const;
};

#endif // BEEPINTVALIDATOR_H

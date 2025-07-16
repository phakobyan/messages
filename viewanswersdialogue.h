#pragma once
#include <QDialog>

namespace Ui {
class ViewAnswersDialogue;
}

class ViewAnswersDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAnswersDialogue(const QMap<QString, QString>& answers,QWidget *parent = nullptr);
    ~ViewAnswersDialogue();

private:
    Ui::ViewAnswersDialogue *ui;
};

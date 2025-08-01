#include "viewanswersdialogue.h"
#include "ui_viewanswersdialogue.h"
#include <QDebug>

ViewAnswersDialogue::ViewAnswersDialogue(const QMap<QString, QString>& answers,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAnswersDialogue)
{

    ui->setupUi(this);

    QString content;

    for (auto it = answers.begin(); it != answers.end(); ++it) {
        if(not content.isEmpty()){
            content += '\n';
        }
        content += it.key() + ": " + it.value();
    }

    qDebug()<<answers;
    ui->label->setText(content);
}

ViewAnswersDialogue::~ViewAnswersDialogue()
{
    delete ui;
}

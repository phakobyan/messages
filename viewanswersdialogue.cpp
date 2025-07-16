#include "viewanswersdialogue.h"
#include "ui_viewanswersdialogue.h"

ViewAnswersDialogue::ViewAnswersDialogue(const QMap<QString, QString>& answers,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewAnswersDialogue)
{

    ui->setupUi(this);

    QString content;

    for (const auto& key : answers.keys()) {
        if(not content.isEmpty()){
            content += '\n';
        }
        content += key + ": " + answers[key];
    }

    ui->label->setText(content);
}

ViewAnswersDialogue::~ViewAnswersDialogue()
{
    delete ui;
}

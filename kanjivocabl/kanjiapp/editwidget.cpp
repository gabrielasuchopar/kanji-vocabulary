#include "editwidget.h"
#include "ui_editwidget.h"

EditWidget::EditWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditWidget)
{
    ui->setupUi(this);
}

EditWidget::~EditWidget()
{
    delete ui;
}

void EditWidget::on_confirm_button_clicked()
{

}
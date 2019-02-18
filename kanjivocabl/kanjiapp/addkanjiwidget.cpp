#include "addkanjiwidget.h"
#include "ui_addkanjiwidget.h"

#include <QPushButton>
#include <QMessageBox>
#include <QLabel>

AddKanjiWidget::AddKanjiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddKanjiWidget)
{
    ui->setupUi(this);

    setupLayout();
}

AddKanjiWidget::~AddKanjiWidget()
{
    delete ui;
}


void AddKanjiWidget::onAddClicked()
{
    auto k = kanji_l->text().toStdWString();
    auto r = reading_l->text().toStdWString();
    auto m = meaning_l->text().toStdWString();

    if (k == L"" || r == L"" || m == L"") {
        QMessageBox emptyBox;
        emptyBox.setText("Cannot add kanji");
        emptyBox.setInformativeText("Some of the fields are empty.");
        emptyBox.addButton(QMessageBox::Ok);
        emptyBox.exec();
        return;
    }

    emit kanjiAddRequested(kcomp(k, r, m));
}

void AddKanjiWidget::onAddSucceeded(kcomp kc)
{
    kanji_l->setText("");
    reading_l->setText("");
    meaning_l->setText("");
}

void AddKanjiWidget::setupLayout()
{
    l = new QVBoxLayout();

    QLabel *kanjiLabel = new QLabel("Kanji");
    kanji_l = new QLineEdit();

    auto font = kanji_l->font();
    font.setPixelSize(32);
    kanji_l->setFont(font);

    QLabel *readingLabel = new QLabel("Reading");
    reading_l = new QLineEdit();

    QLabel *meaningLabel = new QLabel("Meaning");
    meaning_l = new QLineEdit();

    l->addWidget(kanjiLabel);
    l->addWidget(kanji_l);

    l->addWidget(readingLabel);
    l->addWidget(reading_l);

    l->addWidget(meaningLabel);
    l->addWidget(meaning_l);

    setupButtons();

    l->addStretch();
    setLayout(l);
}

void AddKanjiWidget::setupButtons()
{
    QPushButton *addButton = new QPushButton("Add kanji");
    connect(addButton, &QPushButton::clicked,
            this, &AddKanjiWidget::onAddClicked);

    l->addWidget(addButton);
}

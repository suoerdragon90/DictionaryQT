#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked()
{
    QString word = ui->wordLineEdit->text().trimmed();
    QString arabicMeaning = ui->meaningLineEdit->text().trimmed();

    if (word.isEmpty() || arabicMeaning.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter both English word and Arabic meaning.");
        return;
    }

    dictionary.insert(word, arabicMeaning);
    QMessageBox::information(this, "Success", "Word inserted successfully.");

    ui->wordLineEdit->clear();
    ui->meaningLineEdit->clear();
}

void MainWindow::on_searchButton_clicked()
{
    QString word = ui->wordLineEdit->text().trimmed();

    if (word.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a word to search.");
        return;
    }

    QString arabicMeaning;
    if (dictionary.search(word, arabicMeaning)) {
        ui->meaningLineEdit->setText(arabicMeaning);
    } else {
        QMessageBox::information(this, "Not Found", "Word not found in the dictionary.");
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QString word = ui->wordLineEdit->text().trimmed();

    if (word.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a word to delete.");
        return;
    }

    if (dictionary.remove(word)) {
        QMessageBox::information(this, "Success", "Word deleted successfully.");
        ui->wordLineEdit->clear();
        ui->meaningLineEdit->clear();
    } else {
        QMessageBox::information(this, "Not Found", "Word not found in the dictionary.");
    }
}

void MainWindow::on_displayButton_clicked()
{
    QString allWords = dictionary.getAllWords();
    ui->displayTextEdit->setText(allWords);
}


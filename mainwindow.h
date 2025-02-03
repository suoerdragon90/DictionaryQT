#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linkedlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insertButton_clicked();
    void on_searchButton_clicked();
    void on_deleteButton_clicked();
    void on_displayButton_clicked();

private:
    Ui::MainWindow *ui;
    LinkedList dictionary;
};
#endif


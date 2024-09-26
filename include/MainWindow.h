#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>

#include "Model.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTableView* _table;
    Model* _defaultModel;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H

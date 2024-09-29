#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../../include/model/ZipInfoStorage.h"
#include "CentralWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /* backend */

    ZipInfoStorage* _storage;

    /* frontend */

    CentralWidget* _central_wgt;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void search_zip();
    void clean_zip();

}; //class MainWindow
//-------------------------------------------------------------------

#endif // MAINWINDOW_H

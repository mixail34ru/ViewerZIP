#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CentralWidget.h"

class ZipInfoStorage;
class ZipFilesViewer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /* backend */

    ZipInfoStorage* _storage;
    ZipFilesViewer* _zipViewer;

    /* frontend */

    CentralWidget* _central_wgt;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void search_zip(QString dir_path);
    void clean_zip();

}; //class MainWindow
//-------------------------------------------------------------------

#endif // MAINWINDOW_H

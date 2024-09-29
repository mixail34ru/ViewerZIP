#include "../../include/view/MainWindow.h"

#include "../../include/model/ZipInfoStorage.h"
#include "../../include/model/ZipFilesViewer.h"

#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* backend */
    _storage = new ZipInfoStorage(this);
    _zipViewer = new ZipFilesViewer(_storage, this);

    ZipInfoStorageViewInterface* delegate
        = new ZipInfoStorageViewInterface(_storage, this);


    /* frontend */
    QMenu* referenceMenu = new QMenu(tr("Справка"));
    referenceMenu->addAction(tr("О программе"), this, &MainWindow::about_program);

    QMenuBar* bar = new QMenuBar();
    bar->addMenu(referenceMenu);

    this->setMenuBar(bar);

    _central_wgt = new CentralWidget(delegate, this);
    connect(_central_wgt, SIGNAL(searchStarted(QString)),
            this, SLOT(search_zip(QString)));

    connect(_central_wgt, SIGNAL(cleanTableStarted()),
            this, SLOT(clean_zip()));

    this->setMinimumSize(320, 240);
    this->setWindowIcon(QIcon(QString("")));
    setCentralWidget(_central_wgt);


    // constexpr int rows = 10;
    // constexpr int columns = 5;
    // QStandardItemModel* model = new QStandardItemModel(rows, columns);
    // for(int row = 0; row < rows; ++row) {
    //     for(int col = 0; col < columns; ++col) {
    //         model->setItem(row, col, new QStandardItem(QString("(%1,%2").arg(row).arg(col)));
    //     }
    // }

    //auto verticalHeader = _table->verticalHeader();
    //auto horizontalHeader = _table->horizontalHeader();

    // auto layout = new QBoxLayout(QBoxLayout::Direction());
    // layout->addStretch();
    // layout->addWidget(_table);
    // layout->addStretch();

    // auto wgt_central = new QWidget();
    // wgt_central->setLayout(layout);

    // this->setCentralWidget(wgt_central);
    // this->setMinimumSize(320, 240);
    // this->show();
}

MainWindow::~MainWindow() {

}

void MainWindow::search_zip(QString dir_path) {
    _zipViewer->search_zip(dir_path);
}

void MainWindow::clean_zip() {
    _zipViewer->clean_zip();
}

void MainWindow::about_program() {
    QWidget * _aboutProgWgt = new QWidget();

    _aboutProgWgt->setAttribute(Qt::WA_DeleteOnClose);
    _aboutProgWgt->setWindowFlags(Qt::WindowCloseButtonHint);
    _aboutProgWgt->setWindowTitle(tr("О программе"));
    _aboutProgWgt->setFixedSize(240, 120);
    _aboutProgWgt->activateWindow();

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addWidget(new QLabel(tr("Автор: Кучеренков Михаил Петрович.")));

    _aboutProgWgt->setLayout(v_layout);

    _aboutProgWgt->show();
}

#include "../../include/view/MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* backend */
    _storage = new ZipInfoStorage();
    ZipInfoStorageViewDelegate* delegate = new ZipInfoStorageViewDelegate(_storage);

    /* frontend */
    _central_wgt = new CentralWidget(delegate, this);
    connect(_central_wgt, SIGNAL(searchStarted()), this, SLOT(search_zip()));

    this->setMinimumSize(320, 240);
    setCentralWidget(_central_wgt /*_treeView*/);




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
    delete _storage;
}

void MainWindow::search_zip() {
    QString str = QString("absolute_path_") + QString::number(_storage->size() + 1);

    _storage->push_back(
        ZIPInfo {
            str,
            _storage->size() + 1,
            _storage->size() + 1
        }
    );

    //_central_wgt->update();
}

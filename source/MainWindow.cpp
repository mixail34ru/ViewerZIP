#include "../include/MainWindow.h"

// #include <QWidget>
// #include <QBoxLayout>
#include <QHeaderView>

// #include <QString>
// #include <QStringList>
// #include <QStandardItem>
// #include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumSize(320, 240);

    _defaultModel = new Model(this);

    _table = new QTableView(this);
    _table->setModel(_defaultModel);

    //verticalHeader
    //_table->verticalHeader()->hide();
    _table->verticalHeader()->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    _table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    _table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //horizontalHeader
    _table->horizontalHeader()->setSectionsClickable(true);

    _table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    _table->horizontalHeader()->setHighlightSections(true);
    _table->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    _table->horizontalHeader()->setStretchLastSection(true);
    _table->horizontalHeader()->setSectionsMovable(true);

    /* Тестирую модель */
    _defaultModel->setData(_defaultModel->index(1, 1), tr("тест"), Qt::DisplayRole);
    _defaultModel->insertRows(1, 3);
    _defaultModel->removeRows(1, 2);

    setCentralWidget(_table /*_treeView*/);




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

MainWindow::~MainWindow() {}

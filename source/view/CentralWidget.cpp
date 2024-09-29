#include "../../include/view/CentralWidget.h"
#include "../../include/view/TableModel.h"

#include <QBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

CentralWidget::CentralWidget(
    ZipInfoStorageViewInterface* storage, QWidget* parent)
{
    /* backend */
    TableModel* tableModel = new TableModel(storage, this);

    /* frontend */
    _tableView = new TableView(tableModel, this);

    _search_btn = new QPushButton(tr("Выполнить поиск"));
    connect(_search_btn, SIGNAL(clicked(bool)), this, SIGNAL(searchStarted()));

    _clean_btn = new QPushButton(tr("Очистить список"));
    connect(_clean_btn, SIGNAL(clicked(bool)), this, SIGNAL(cleanTableStarted()));

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addWidget(_search_btn);
    v_layout->addWidget(_clean_btn);

    QBoxLayout* layout = new QBoxLayout(QBoxLayout::Direction());
    //layout->addStretch();
    layout->addWidget(_tableView);
    //layout->addStretch();

    v_layout->addLayout(layout);

    this->setLayout(v_layout);
}

CentralWidget::~CentralWidget()
{

}

/* private slots */
// void CentralWidget::on_search_btn_clicked() {
//     emit searchStarted();
// }

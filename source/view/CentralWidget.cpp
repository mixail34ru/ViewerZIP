#include "../../include/view/CentralWidget.h"
#include "../../include/view/TableModel.h"

#include <QBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

CentralWidget::CentralWidget(
    ZipInfoStorageViewDelegate* storage, QWidget* parent)
{
    /* backend */
    TableModel* tableModel = new TableModel(storage, this);

    /* frontend */
    _tableView = new TableView(tableModel, this);

    _search_btn = new QPushButton(tr("Выполнить поиск"));
    connect(_search_btn, SIGNAL(clicked(bool)), this, SLOT(on_search_btn_clicked()));

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addWidget(_search_btn);

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
void CentralWidget::on_search_btn_clicked() {
    emit searchStarted();
}

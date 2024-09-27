#include "../../include/view/TableView.h"

#include <QHeaderView>

TableView::TableView(QAbstractTableModel* model, QWidget* parent)
    : QTableView(parent)
{
    this->setModel(model);

    /* verticalHeader */
    //_table->verticalHeader()->hide();
    this->verticalHeader()->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    /* horizontalHeader */
    this->horizontalHeader()->setSectionsClickable(true);

    this->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    this->horizontalHeader()->setHighlightSections(true);
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    this->horizontalHeader()->setStretchLastSection(true);
    this->horizontalHeader()->setSectionsMovable(true);
}

TableView::~TableView() {

}

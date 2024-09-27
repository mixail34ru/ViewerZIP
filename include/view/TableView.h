#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>

class TableView : public QTableView
{
    Q_OBJECT

public:
    explicit TableView(QAbstractTableModel* model, QWidget* parent);
    ~TableView();

}; //class TableView
//-------------------------------------------------------------------

#endif // TABLEVIEW_H

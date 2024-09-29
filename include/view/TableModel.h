#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

#include "../model/ZipInfoStorageViewInterface.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    explicit TableModel(
        ZipInfoStorageViewInterface* storage, QObject *parent);
    ~TableModel();

    bool hasIndex(
        int row,
        int column,
        const QModelIndex &parent = QModelIndex()
    ) const;

    virtual int columnCount(
        const QModelIndex& parent = QModelIndex()
    ) const override;

    virtual int rowCount(
        const QModelIndex& parent = QModelIndex()
    ) const override;

    virtual QVariant data(
        const QModelIndex& index,
        int role = Qt::DisplayRole
    ) const override;

    virtual QVariant headerData(
        int section,
        Qt::Orientation orientation,
        int role = Qt::DisplayRole
    ) const override;

    virtual QModelIndex index(
        int row,
        int column,
        const QModelIndex &parent = QModelIndex()
    ) const override;

    virtual QModelIndex parent(
        const QModelIndex &index
    ) const override;

    // bool insertRow(int row, const QModelIndex &parent = QModelIndex());

    // virtual bool insertRows(
    //     int row,
    //     int count,
    //     const QModelIndex &parent = QModelIndex()
    // ) override;

    // bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    // virtual bool removeRows(
    //     int row, int count, const QModelIndex &parent = QModelIndex()
    // ) override;

protected:
    std::vector<QString> _headers;
    ZipInfoStorageViewInterface* _storage;

    void _headerFormer();

private slots:
    //void update_data_table();

    void add_data_row();
    void clear_table();

}; //class TableModel
//-------------------------------------------------------------------

#endif // TABLEMODEL_H

#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>

class Model : public QAbstractTableModel
{
    Q_OBJECT

public:

    Model(QObject *parent);
    ~Model();

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

    virtual bool setData(
        const QModelIndex &index,
        const QVariant &value,
        int role
    ) override;

    bool insertRow(int row, const QModelIndex &parent = QModelIndex());

    virtual bool insertRows(
        int row,
        int count,
        const QModelIndex &parent = QModelIndex()
    ) override;

    bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    virtual bool removeRows(
        int row, int count, const QModelIndex &parent = QModelIndex()
    ) override;

protected:

    std::vector<QString> _headers;
    std::vector<std::vector<QVariant>> _data;

    void _headerFormer();
    void _dataFormer();
};

#endif // MODEL_H

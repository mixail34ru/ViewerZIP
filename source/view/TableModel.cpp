#include "../../include/view/TableModel.h"

TableModel::TableModel(ZipInfoStorageViewInterface* storage, QObject *parent)
    : _storage(storage), QAbstractTableModel(parent)
{
    connect(_storage, SIGNAL(storage_data_added()),
            this, SLOT(add_data_row()));

    connect(_storage, SIGNAL(storage_data_cleared()),
            this, SLOT(clear_table()));

    _headerFormer();
}

TableModel::~TableModel()
{
}

bool TableModel::hasIndex(
    int row, int column, const QModelIndex & parent) const
{
    if (row < 0 || column < 0) return false;

    return row < rowCount(parent) && column < columnCount(parent);
}

int TableModel::columnCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return 3;
}

int TableModel::rowCount(const QModelIndex & parent) const {
    return _storage->size();
}

QVariant TableModel::data(const QModelIndex & index, int role) const {
    if (!index.isValid()) return QVariant();

    if (role == Qt::DisplayRole) {
        int row = index.row();
        int col = index.column();

        if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
            return QVariant();
        }

        switch(col) {
        case 0: return _storage->get_absolute_path(row);
        case 1: return _storage->get_decompress_size(row);
        case 2: return _storage->get_compressed_size(row);
        default: return QVariant();
        }
    }
    return QVariant();
}

QVariant TableModel::headerData
    (int section, Qt::Orientation orientation, int role) const
{
    if ((section < 0)
        || ((orientation == Qt::Horizontal) && (section >= columnCount()))
        || ((orientation == Qt::Vertical) && (section >= rowCount())))
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (role) {
        case Qt::DisplayRole:
            return _headers[section];
            break;
        }
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

QModelIndex TableModel::index(
    int row, int column, const QModelIndex & parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QModelIndex TableModel::parent(const QModelIndex & index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}

// bool TableModel::insertRow(int row, const QModelIndex &parent) {
//     return insertRows(row, 1, parent);
// }

// bool TableModel::insertRows(
//     int row, int count, const QModelIndex &parent)
// {
//     if (row < 0 || row > rowCount() || count < 0) return false;

//     beginInsertRows(parent, row, row + count - 1);
//     endInsertRows();

//     return true;
// }

// bool TableModel::removeRow(int row, const QModelIndex &parent) {
//     return removeRows(row, 1, parent);
// }

// bool TableModel::removeRows(
//     int row, int count, const QModelIndex &parent)
// {
//     if (row < 0 || row > rowCount() || count < 0) return false;

//     if ((row + count) >= _storage->size())
//          count = _storage->size();

//     beginRemoveRows(QModelIndex(), row, row + count - 1);
//     endRemoveRows();

//     return true;
// }

/* protected: */

void TableModel::_headerFormer() {
    _headers =
    {
        tr("Полный путь"),
        tr("Расжатый размер"),
        tr("Сжатый размер")
    };
}

/* private slots: */

void TableModel::add_data_row() {
    beginInsertRows(QModelIndex(), 0, 0);
    endInsertRows();
}

void TableModel::clear_table() {
    beginResetModel();
    endResetModel();
}

//void TableModel::update_data_table()
//{
    //beginInsertRows(QModelIndex(), 0, 0);
    //endInsertRows();

    //beginResetModel();
    //endResetModel();

    // auto topLeft = index(0, 0, QModelIndex());
    // auto bottomRight = index(rowCount() - 1, columnCount() - 1, QModelIndex());

    // auto val_left = topLeft.isValid();
    // auto val_right = bottomRight.isValid();

    // insertRow(rowCount());

    // emit dataChanged(topLeft, bottomRight);
//}

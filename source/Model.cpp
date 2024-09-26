#include "../include/Model.h"

Model::Model(QObject *parent)
    : QAbstractTableModel(parent)
{
    _headerFormer();
    _dataFormer();
}

Model::~Model()
{
}

bool Model::hasIndex(
    int row, int column, const QModelIndex & parent) const
{
    if (row < 0 || column < 0) return false;

    return row < rowCount(parent) && column < columnCount(parent);
}

int Model::columnCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return _headers.size();
}

int Model::rowCount(const QModelIndex & parent) const {
    return _data.size();
}

QVariant Model::data(const QModelIndex & index, int role) const {
    if (role == Qt::DisplayRole) {
        int row = index.row();
        int col = index.column();

        if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
            return QVariant();
        }

        return _data.at(row).at(col);
    }
    return QVariant();
}

QVariant Model::headerData
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

QModelIndex Model::index(
    int row, int column, const QModelIndex & parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

QModelIndex Model::parent(const QModelIndex & index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}

bool Model::setData(
    const QModelIndex & index, const QVariant & value, int role)
{
    int row = index.row();
    int col = index.column();

    if (row < 0 || row >= rowCount() || col < 0 || col >= columnCount()) {
        return false;
    }

    if (role == Qt::DisplayRole) {
        _data.at(row).at(col) = value;
        return true;
    }

    return false;
}

bool Model::insertRow(int row, const QModelIndex &parent) {
    return insertRows(row, 1, parent);
}

bool Model::insertRows(
    int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > rowCount() || count < 0) return false;

    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i) {
        _data.push_back(std::vector<QVariant>({ tr(""), tr(""), tr("") }));
    }
    endInsertRows();

    return true;
}

bool Model::removeRow(int row, const QModelIndex &parent) {
    return removeRows(row, 1, parent);
}

bool Model::removeRows(
    int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > rowCount() || count < 0) return false;

    if ((row + count) >= _data.size())
        count = _data.size();

    beginRemoveRows(QModelIndex(), row, row + count - 1);
    _data.erase(_data.begin() + row, _data.begin() + row + count - 1);
    endRemoveRows();

    return true;
}

/* protected: */

void Model::_headerFormer() {
    _headers =
    {
        tr("Полный путь"),
        tr("Расжатый размер"),
        tr("Сжатый размер")
    };
}

void Model::_dataFormer() {
    std::vector<QVariant> list1{
        tr("absolute_path_1"),
        tr("full_size_1"),
        tr("compressed_size_1")
    }; _data.push_back(list1);

    std::vector<QVariant> list2{
        tr("absolute_path_2"),
        tr("full_size_2"),
        tr("compressed_size_2")
    }; _data.push_back(list2);
}

#include "../../include/model/ZipInfoStorageViewDelegate.h"

ZipInfoStorageViewDelegate::ZipInfoStorageViewDelegate(ZipInfoStorage* storage)
    : _storage(storage)
{
    connect(_storage, SIGNAL(storage_data_updated()), this, SLOT(storage_data_update()));
}

ZipInfoStorageViewDelegate::~ZipInfoStorageViewDelegate()
{

}

int ZipInfoStorageViewDelegate::size() const {
    return _storage->size();
}

QString ZipInfoStorageViewDelegate::get_absolute_path(int index) const {
    return _storage->get_absolute_path(index);
}

int ZipInfoStorageViewDelegate::get_compressed_size(int index) const {
    return _storage->get_compressed_size(index);
}

int ZipInfoStorageViewDelegate::get_decompress_size(int index) const {
    return _storage->get_decompress_size(index);
}

void ZipInfoStorageViewDelegate::storage_data_update() {
    emit storage_data_updated();
}

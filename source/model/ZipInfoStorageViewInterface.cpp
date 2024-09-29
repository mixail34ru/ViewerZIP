#include "../../include/model/ZipInfoStorage.h"
#include "../../include/model/ZipInfoStorageViewInterface.h"

ZipInfoStorageViewInterface::ZipInfoStorageViewInterface(
    ZipInfoStorage* storage, QObject* parent)
    : QObject(parent), _storage(storage)
{
    connect(_storage, SIGNAL(storage_data_added()),
            this, SIGNAL(storage_data_added()));

    connect(_storage, SIGNAL(storage_data_cleared()),
            this, SIGNAL(storage_data_cleared()));
}

ZipInfoStorageViewInterface::~ZipInfoStorageViewInterface()
{

}

int ZipInfoStorageViewInterface::size() const {
    return _storage->size();
}

QString ZipInfoStorageViewInterface::get_absolute_path(int index) const {
    return _storage->get_absolute_path(index);
}

int ZipInfoStorageViewInterface::get_compressed_size(int index) const {
    return _storage->get_compressed_size(index);
}

int ZipInfoStorageViewInterface::get_decompress_size(int index) const {
    return _storage->get_decompress_size(index);
}

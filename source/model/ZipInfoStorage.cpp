#include "../../include/model/ZipInfoStorage.h"

ZipInfoStorage::ZipInfoStorage(QObject* parent)
    : QObject(parent)
{
    _create_data();
}

ZipInfoStorage::~ZipInfoStorage() {}

void ZipInfoStorage::push_back(ZIPInfo info) {
    _vec_info.push_back(info);
    emit storage_data_added();
}

void ZipInfoStorage::clear() {
    _vec_info.clear();
    emit storage_data_cleared();
}

int ZipInfoStorage::size() const {
    return _vec_info.size();
}

ZIPInfo ZipInfoStorage::at(int index) const {
    if (index >= 0 && index < size()) {
        return _vec_info.at(index);
    }

    return ZIPInfo();
}

QString ZipInfoStorage::get_absolute_path(int index) const {
    return at(index).absolute_path;
}

int ZipInfoStorage::get_compressed_size(int index) const {
    return at(index).compressed_size;
}

int ZipInfoStorage::get_decompress_size(int index) const {
    return at(index).decompress_size;
}

void ZipInfoStorage::_create_data() {
    push_back(ZIPInfo { "absolute_path_1", 1, 1 } );
    push_back(ZIPInfo { "absolute_path_2", 2, 2 } );
    push_back(ZIPInfo { "absolute_path_3", 3, 3 } );
    push_back(ZIPInfo { "absolute_path_4", 4, 4 } );
}

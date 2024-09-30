#include "../../include/model/ZipFilesViewer.h"
#include "../../include/model/ZipInfoStorage.h"

#include <QString>

//#include "../../libs/minizip-ng/mz.h"
//#include "../../libs/minizip-ng/mz_zip.h"

ZipFilesViewer::ZipFilesViewer(
    ZipInfoStorage* storage, QObject* parent)
    : QObject(parent), _storage(storage)
{
    _create_data();
}

ZipFilesViewer::~ZipFilesViewer()
{

}

void ZipFilesViewer::search_zip(QString dir_path) {
    _storage->push_back(_read_zip_info(dir_path));
}

void ZipFilesViewer::clean_zip() {
    _storage->clear();
}

/* private: */

void ZipFilesViewer::_create_data() {
    _storage->push_back(_read_zip_info("absolute_path_1"));
    _storage->push_back(_read_zip_info("absolute_path_2"));
    _storage->push_back(_read_zip_info("absolute_path_3"));
    _storage->push_back(_read_zip_info("absolute_path_4"));
}

ZIPInfo ZipFilesViewer::_read_zip_info(QString dir_path) {
    ZIPInfo info;
    info.absolute_path = dir_path;
    info.compressed_size = dir_path.length();
    info.decompress_size = dir_path.length();

    //void* zip_handle = mz_zip_create();
    //mz_zip_delete(&zip_handle);

    return info;
}

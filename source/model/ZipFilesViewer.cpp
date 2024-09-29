#include "../../include/model/ZipFilesViewer.h"
#include "../../include/model/ZipInfoStorage.h"

#include <QString>

//#include "mz.h"
//#include "mz_zip.h"

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
    QString str = QString("absolute_path_") + QString::number(_storage->size() + 1);

    _storage->push_back(
        ZIPInfo {
            str,
            _storage->size() + 1,
            _storage->size() + 1
        }
    );
}

void ZipFilesViewer::clean_zip() {
    _storage->clear();
}

/* private: */

void ZipFilesViewer::_create_data() {
    _storage->push_back(ZIPInfo { "absolute_path_1", 1, 1 } );
    _storage->push_back(ZIPInfo { "absolute_path_2", 2, 2 } );
    _storage->push_back(ZIPInfo { "absolute_path_3", 3, 3 } );
    _storage->push_back(ZIPInfo { "absolute_path_4", 4, 4 } );
}

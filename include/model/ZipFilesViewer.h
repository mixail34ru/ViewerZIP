#ifndef ZIPFILESVIEWER_H
#define ZIPFILESVIEWER_H

#include "../../include/model/ZipInfoStorage.h"

#include <QObject>

class ZipFilesViewer : public QObject
{
public:
    ZipFilesViewer(ZipInfoStorage* storage, QObject* parent = nullptr);
    ~ZipFilesViewer();

    void search_zip(QString dir_path);
    void clean_zip();

private:
    ZipInfoStorage* _storage;

    void _create_data();

    ZIPInfo read_zip_info();


}; //class ZipFilesViewer
//-------------------------------------------------------------------

#endif // ZIPFILESVIEWER_H

#ifndef ZIPINFOSTORAGEVIEWDELEGATE_H
#define ZIPINFOSTORAGEVIEWDELEGATE_H

#include "ZipInfoStorage.h"

#include <QString>

class ZipInfoStorageViewDelegate : public QObject
{
    Q_OBJECT

public:
    explicit ZipInfoStorageViewDelegate(ZipInfoStorage* storage);
    ~ZipInfoStorageViewDelegate();

    int size() const;

    QString get_absolute_path(int index) const;

    int get_compressed_size(int index) const;

    int get_decompress_size(int index) const;

private:
    ZipInfoStorage* _storage;

private slots:
    void storage_data_update();

signals:
    void storage_data_updated();

}; //class ZipInfoStorageViewDelegate
//-------------------------------------------------------------------

#endif // ZIPINFOSTORAGEVIEWDELEGATE_H

#ifndef ZIPINFOSTORAGEVIEWINTERFACE_H
#define ZIPINFOSTORAGEVIEWINTERFACE_H

#include <QString>

class ZipInfoStorage;

class ZipInfoStorageViewInterface : public QObject
{
    Q_OBJECT

public:
    explicit ZipInfoStorageViewInterface(
        ZipInfoStorage* storage, QObject* parent = nullptr);
    ~ZipInfoStorageViewInterface();

    int size() const;

    QString get_absolute_path(int index) const;

    int get_compressed_size(int index) const;

    int get_decompress_size(int index) const;

private:
    ZipInfoStorage* _storage;

signals:
    void storage_data_added();
    void storage_data_cleared();

}; //class ZipInfoStorageViewDelegate
//-------------------------------------------------------------------

#endif // ZIPINFOSTORAGEVIEWINTERFACE_H

#ifndef ZIPINFOSTORAGE_H
#define ZIPINFOSTORAGE_H

#include <QVector>
#include <QVariant>
#include <QObject>

struct ZIPInfo {
    QString absolute_path = "";
    int compressed_size = 0;
    int decompress_size = 0;
}; //struct ZIPInfo
//-------------------------------------------------------------------

class ZipInfoStorage : public QObject
{
    Q_OBJECT

public:
    ZipInfoStorage();
    ~ZipInfoStorage();

    void push_back(ZIPInfo info);
    void clear();
    ZIPInfo at(int index) const;

    int size() const;
    QString get_absolute_path(int index) const;
    int get_compressed_size(int index) const;
    int get_decompress_size(int index) const;

private:
    QVector<ZIPInfo> _vec_info;

    void _create_data();

signals:
    void storage_data_updated();

}; //class ZipInfoStorage
//-------------------------------------------------------------------

#endif // ZIPINFOSTORAGE_H

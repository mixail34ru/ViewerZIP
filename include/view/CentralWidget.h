#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QPushButton>

#include "TableView.h"
#include "../../include/model/ZipInfoStorageViewDelegate.h"

class CentralWidget : public QWidget
{
    Q_OBJECT

    QPushButton* _search_btn;
    TableView* _tableView;

public:
    explicit CentralWidget(
        ZipInfoStorageViewDelegate* storage, QWidget* parent = nullptr
    );
    ~CentralWidget();

private slots:
    void on_search_btn_clicked();

signals:
    void searchStarted();
};

#endif // CENTRALWIDGET_H

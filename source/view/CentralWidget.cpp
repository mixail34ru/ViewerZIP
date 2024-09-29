#include "../../include/view/CentralWidget.h"
#include "../../include/view/TableModel.h"

#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>

CentralWidget::CentralWidget(
    ZipInfoStorageViewInterface* storage, QWidget* parent)
{
    /* backend */
    TableModel* tableModel = new TableModel(storage, this);

    /* frontend */
    _textEdit = new QTextEdit();
    _textEdit->setReadOnly(true);

    _search_btn = new QPushButton(tr("Выполнить поиск"));
    connect(_search_btn, SIGNAL(clicked(bool)), this, SLOT(on_search_btn_clicked()));

    //_textEdit->setFixedWidth(_search_btn->size().width());
    //_textEdit->setMaximumHeight(_search_btn->size().height());

    //QHBoxLayout* h_layout = new QHBoxLayout();
    //h_layout->addWidget(_textEdit);
    //h_layout->addWidget(_search_btn);
    //h_layout->addStretch();

    _clean_btn = new QPushButton(tr("Очистить список"));
    connect(_clean_btn, SIGNAL(clicked(bool)), this, SIGNAL(cleanTableStarted()));

    QVBoxLayout* v_layout = new QVBoxLayout();
    //v_layout->addLayout(h_layout);
    v_layout->addWidget(_textEdit);
    v_layout->addWidget(_search_btn);
    v_layout->addWidget(_clean_btn);

    _tableView = new TableView(tableModel, this);

    QBoxLayout* layout = new QBoxLayout(QBoxLayout::Direction());
    //layout->addStretch();
    layout->addWidget(_tableView);
    //layout->addStretch();

    v_layout->addLayout(layout);

    this->setLayout(v_layout);
}

CentralWidget::~CentralWidget()
{

}

void CentralWidget::on_search_btn_clicked()
{
    QString dir_path = QFileDialog::getExistingDirectory(
        this, tr("Open Directory"),
        "/home",
        QFileDialog::ShowDirsOnly
        | QFileDialog::DontResolveSymlinks
    );

    _textEdit->setText(dir_path);

    if (dir_path.length()) emit searchStarted(dir_path);
}

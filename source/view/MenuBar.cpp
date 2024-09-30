#include "../../include/view/MenuBar.h"

#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QLabel>

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
{
    QMenu* referenceMenu = new QMenu(tr("Справка"));
    referenceMenu->addAction(tr("О программе"), this, &MenuBar::about_program);

    this->addMenu(referenceMenu);
}

MenuBar::~MenuBar()
{

}

void MenuBar::about_program() {
    QWidget * _aboutProgWgt = new QWidget();

    _aboutProgWgt->setAttribute(Qt::WA_DeleteOnClose);
    _aboutProgWgt->setWindowFlags(Qt::WindowCloseButtonHint);
    _aboutProgWgt->setWindowTitle(tr("О программе"));
    _aboutProgWgt->setFixedSize(240, 120);
    _aboutProgWgt->activateWindow();

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addWidget(new QLabel(tr("Автор: Кучеренков Михаил Петрович.")));

    _aboutProgWgt->setLayout(v_layout);

    _aboutProgWgt->show();
}

#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    MenuBar(QWidget *parent = nullptr);
    ~MenuBar();

private:
    void about_program();

}; //class MenuBar
//-------------------------------------------------------------------

#endif // MENUBAR_H

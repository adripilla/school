#include "my_qlabel.h"

my_qlabel::my_qlabel()
{

}

void my_qlabel::mousePressEvent(QMouseEvent *ev)
{
   emit MOUSE_Pressed();
}

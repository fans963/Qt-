#include "mybutton.h"
#include <QMouseEvent>
#include <QPainter>

MyButton::MyButton(QWidget *parent) : ElaToolButton(parent)
{

}

void MyButton::setImage(QString normal, QString hover, QString pressed)
{
    m_normal = normal;
    m_hover = hover;
    m_pressed = pressed;
    m_pixmap.load(m_normal);
    update();
}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_pixmap.load(m_pressed);
        update();
    }
    ElaToolButton::mousePressEvent(ev);
}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_pixmap.load(m_normal);
        update();
    }
    ElaToolButton::mouseReleaseEvent(ev);
}

void MyButton::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev)
    m_pixmap.load(m_hover);
    update();
}

void MyButton::leaveEvent(QEvent *ev)
{
    Q_UNUSED(ev)
    m_pixmap.load(m_normal);
    update();
}

void MyButton::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev)
    QPainter p(this);
    p.drawPixmap(rect(), m_pixmap);
}

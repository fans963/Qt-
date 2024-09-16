#ifndef MYBUTTON_H
#define MYBUTTON_H

#include "ElaToolButton.h"

class MyButton : public ElaToolButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

    void setImage(QString normal, QString hover, QString pressed);

signals:

protected:
    void mousePressEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
    void enterEvent(QEvent* ev);
    void leaveEvent(QEvent* ev);
    void paintEvent(QPaintEvent* ev);

private:
    QString m_normal;
    QString m_hover;
    QString m_pressed;
    QPixmap m_pixmap;

};

#endif // MYBUTTON_H

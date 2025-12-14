#pragma once

#include <QWidget>
#include <QPointF>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget* parent = nullptr);

signals:
    void positionComputed(int pos);  // 1, -1 или 0

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    QPointF m_A;
    QPointF m_B;
    QPointF m_P;
    int     m_clickCount; // 0,1,2,3
};

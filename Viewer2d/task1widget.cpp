#include "task1widget.h"
#include <QMouseEvent>
#include <QPainter>

// наши алгоритмы из PlaneGeometry
#include "point.h"
#include "task1.h"

namespace {
Point toPoint(const QPointF& q)
{
    return Point{ q.x(), q.y() };
}
}

DrawWidget::DrawWidget(QWidget* parent)
    : QWidget(parent),
    m_clickCount(0)
{
    setMinimumSize(400, 400);
}

void DrawWidget::mousePressEvent(QMouseEvent* event)
{
    QPointF pos = event->pos();

    if (m_clickCount == 0) {
        m_A = pos;
        m_clickCount = 1;
    } else if (m_clickCount == 1) {
        m_B = pos;
        m_clickCount = 2;
    } else {
        m_P = pos;
        m_clickCount = 3;

        // переводим в нашу структуру и вызываем алгоритм
        Point A = toPoint(m_A);
        Point B = toPoint(m_B);
        Point P = toPoint(m_P);

        int res = pointRelativeToSegment(A, B, P);
        emit positionComputed(res);

        // после вычисления можно начать заново
        m_clickCount = 0;
    }

    update(); // попросить перерисовать
}

void DrawWidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    if (m_clickCount >= 1) {
        p.drawEllipse(m_A, 3, 3);
    }
    if (m_clickCount >= 2) {
        p.drawEllipse(m_B, 3, 3);
        p.drawLine(m_A, m_B);
    }
    if (m_clickCount == 3) {
        p.drawEllipse(m_P, 4, 4);
    }
}

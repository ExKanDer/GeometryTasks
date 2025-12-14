#include "mainwindow.h"
#include "drawwidget.h"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_drawWidget(new DrawWidget(this))
{
    setCentralWidget(m_drawWidget);

    statusBar()->showMessage("Клик 1: A, клик 2: B, клик 3: точка P.");

    connect(m_drawWidget, &DrawWidget::positionComputed,
            this, [this](int pos) {
                statusBar()->showMessage(QString("Результат: %1 (1 слева, -1 справа, 0 на отрезке)")
                                             .arg(pos));
            });
}

MainWindow::~MainWindow() = default;

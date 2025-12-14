#pragma once

#include <QMainWindow>

class DrawWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    DrawWidget* m_drawWidget;
};

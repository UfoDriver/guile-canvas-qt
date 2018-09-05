#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <libguile.h>

#include <QPen>
#include <QVector>
#include <QWidget>

class QPaintEvent;
class QPoint;
class QLine;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    static void* register_functions(void*);
    static MainWindow* canvas;

    void resetCanvas();
    void addPoint(int x, int y);
    void addLine(int x1, int y1, int x2, int y2);
    void setPen(int r, int g, int b);

    // Guile fuctions
    static SCM canvas_reset();
    static SCM draw_point(SCM x, SCM y);
    static SCM draw_line(SCM x1, SCM y1, SCM x2, SCM y2);
    static SCM set_pen_color(SCM r, SCM g, SCM b);

private:
    Ui::MainWindow *ui;
    QVector<QPoint> points;
    QVector<QLine> lines;
    QPen pen;
};

#endif // MAINWINDOW_H

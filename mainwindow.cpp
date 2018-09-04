#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPoint>

#include <libguile.h>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    canvas = this;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow* MainWindow::canvas = NULL;

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.drawPoints(points.data(), points.length());
    painter.drawLines(lines.data(), lines.length());
}

void MainWindow::resetCanvas()
{
    points.clear();
    lines.clear();
    repaint();
}

void MainWindow::addPoint(int x, int y)
{
    points.append(QPoint(x, y));
    repaint();
}

void MainWindow::addLine(int x1, int y1, int x2, int y2)
{
    lines.append(QLine(x1, y1, x2, y2));
    repaint();
}


SCM MainWindow::canvas_reset()
{
    MainWindow::canvas->resetCanvas();
    return SCM_UNSPECIFIED;
}

SCM MainWindow::draw_point(SCM x, SCM y)
{
    MainWindow::canvas->addPoint(scm_to_int(x), scm_to_int(y));
    return SCM_UNSPECIFIED;
}

SCM MainWindow::draw_line(SCM x1, SCM y1, SCM x2, SCM y2)
{
    MainWindow::canvas->addLine(scm_to_int(x1), scm_to_int(y1), scm_to_int(x2), scm_to_int(y2));
    return SCM_UNSPECIFIED;
}

void* MainWindow::register_functions(void*)
{
    scm_c_define_gsubr("reset", 0, 0, 0, (scm_t_subr)&canvas_reset);
    scm_c_define_gsubr("draw-point", 2, 0, 0, (scm_t_subr)&draw_point);
    scm_c_define_gsubr("draw-line", 4, 0, 0, (scm_t_subr)&draw_line);
    return NULL;
}

#include "mainwindow.h"
#include <QApplication>

#include <libguile.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    scm_with_guile(&MainWindow::register_functions, NULL);
//    scm_shell(argc, argv);

    scm_c_eval_string("(use-modules (system repl server))");
    scm_c_eval_string("(spawn-server)");

    return a.exec();
}



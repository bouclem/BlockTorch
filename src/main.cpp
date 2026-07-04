#include <QApplication>
#include "ui/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("BlockTorch");
    app.setApplicationVersion("0.0.3");

    MainWindow window;
    window.show();

    return app.exec();
}

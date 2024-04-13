#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc,
                 argv); // Initialize the QApplication object with arguments
  Widget w;             // Create a widget instance
  w.show();             // Make the widget visible
  return a.exec();      // Run the application until exit() is called
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Worker.h>
#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void UpdateNewMessage(const QString &imgSource);
    void on_SendMessage_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

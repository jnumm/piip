#ifndef PIIP_MAINWINDOW_H
#define PIIP_MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "beepthread.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();
    void on_startStopButton_clicked();
    void on_fromSpinBox_valueChanged(double newValue);
    void on_toSpinBox_valueChanged(double newValue);

private:
    Ui::MainWindow ui;
    BeepThread beepThread;
};

#endif // PIIP_MAINWINDOW_H

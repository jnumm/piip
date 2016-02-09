#include "mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    // Synchronize beepThread with the initial values of the spinboxes
    on_fromSpinBox_valueChanged(ui.fromSpinBox->value());
    on_toSpinBox_valueChanged(ui.toSpinBox->value());
}

MainWindow::~MainWindow()
{
    beepThread.terminate();
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Piip"),
            tr("<p>This application beeps with random time intervals.</p>"
               "<p>Copyright © 2016 Juhani Numminen.<p/>"
               "<p>Made with <a href=\"http://qt.io\">Qt</a>.</p>"));
}

void MainWindow::on_startStopButton_clicked()
{
    if (beepThread.isRunning()) {
        beepThread.terminate();
        ui.startStopButton->setText(tr("&Start"));
        ui.groupBox->setEnabled(true);
    } else {
        beepThread.start();
        ui.startStopButton->setText(tr("&Stop"));
        ui.groupBox->setEnabled(false);
    }
}

void MainWindow::on_fromSpinBox_valueChanged(double newValue)
{
    beepThread.setDelayMin(static_cast<BeepThread::intType>(newValue * 1000));
}

void MainWindow::on_toSpinBox_valueChanged(double newValue)
{
    beepThread.setDelayMax(static_cast<BeepThread::intType>(newValue * 1000));
}

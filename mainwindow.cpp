#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);
    QtLocation = "C:/Qt/5.15.2/mingw81_64/bin/windeployqt ";   
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, "Select the exe files");
    ui->lineEdit->setText(fileName);
    ui->pushButton_2->setEnabled(true);
}
void MainWindow::on_pushButton_2_clicked()
{
    QString l = "\"";
    QString fil = QtLocation + l + ui->lineEdit->text() + l;
    const char* cmd = fil.toLocal8Bit().constData();
    i = system(cmd);
    if(i == 0)
    {
        ui->lineEdit->clear();
        ui->pushButton_2->setDisabled(true);
        QMessageBox::information(this, "Sucess","files has been generated sucessfully");
    }
    else if(i == 1)
    {
        ui->lineEdit->selectAll();
        QMessageBox::warning(this, "Error", "The file Path has an error!");
    }
}
void MainWindow::on_qmlGenerate_clicked()
{
    if(ui->debug->isChecked())
    {
        QString l = "\"";
        QString release = "--debug";
        QString dir = " --qmldir C:/Qt/5.15.2/mingw81_64/qml ";
        QString fil = QtLocation + release + dir + l + ui->lineEdit->text() + l;
        const char* cmd = fil.toLocal8Bit().constData();
        i = system(cmd);
        if(i == 0)
        {
            ui->lineEdit->clear();
            QMessageBox::information(this, "Sucess","files has been generated sucessfully");
        }
        else if(i == 1)
        {
            ui->lineEdit->selectAll();
            QMessageBox::warning(this, "Error", "The file Path has an error!");
        }
    }
    else if(ui->release->isChecked())
    {
        QString l = "\"";
        QString release = "--release";
        QString dir = " --qmldir C:/Qt/5.15.2/mingw81_64/qml ";
        QString fil = QtLocation + release + dir + l + ui->lineEdit->text() + l;
        const char* cmd = fil.toLocal8Bit().constData();
        i = system(cmd);
        if(i == 0)
        {
            ui->lineEdit->clear();
            QMessageBox::information(this, "Sucess","files has been generated sucessfully");
        }
        else if(i == 1)
        {
            ui->lineEdit->selectAll();
            QMessageBox::warning(this, "Error", "The file Path has an error!");
        }
    }
}
void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "Qt");
}

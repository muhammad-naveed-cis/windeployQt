#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_qmlGenerate_clicked();

    void on_actionAbout_Qt_triggered();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QString QtLocation;
    int i;
    int c;
};
#endif // MAINWINDOW_H

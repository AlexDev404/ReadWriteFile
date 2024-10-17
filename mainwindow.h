#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_readFile_clicked();

    void on_writeFile_clicked();

    void on_clearFile_clicked();

    void on_exitApp_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

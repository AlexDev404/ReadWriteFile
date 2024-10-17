#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
QString fileFilter = "All Files (*.*);;Text Files (*.txt)";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_readFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), fileFilter);
    QFile file_is(filename);
    QString Data;

    if(file_is.open(QIODevice::ReadOnly)) {
        QTextStream file_stream(&file_is);

        while(!file_stream.atEnd()) {
            Data += file_stream.readLine() + "\n";
        }

        ui->editPane->setPlainText(Data);
        file_is.close();
    }
}


void MainWindow::on_writeFile_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), fileFilter);
    QFile file_is(filename);

    if(file_is.open(QIODevice::ReadWrite)) {
        QTextStream file_stream(&file_is);
        file_stream << ui->editPane->toPlainText();
        file_is.close();
    }
}


void MainWindow::on_clearFile_clicked()
{
    ui->editPane->setPlainText("");
}


void MainWindow::on_exitApp_clicked()
{
    QCoreApplication::exit(0);
}


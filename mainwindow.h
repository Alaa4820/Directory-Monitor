#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QLabel>
#include <QStatusBar>
#include <QToolBar>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QFont>
#include <iostream>
#include <QMessageBox>
#include "qdirectory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent*);

public slots:
    //metodi menu file
    void saveFile();
    void openFile();
    void exit();



private:
    Ui::MainWindow *ui;
    QString log_filename;
    QDirectory *directory;

    //Menu
    QMenu *fileMenu;

    //Action nel menu "File"
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;

    //metodi di inizializzazione
    void init_menubar();


};
#endif // MAINWINDOW_H

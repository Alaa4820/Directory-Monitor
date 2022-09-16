#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QGuiApplication>
#include <QSaveFile>
#include <QFileDialog>
#include <QClipboard>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    setGeometry(600,300,800,600);
    init_menubar();
    log_filename="log.txt";
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exit);
    directory=new QDirectory();
    directory->loadFile();
    QList<QString> list = directory->keys();
    QList<QString>::const_iterator b,e;
    b=list.begin();
    e=list.end();
    for(; b != e; ++b)
        qDebug() << (*b) ;

}




void MainWindow::openFile(){
    QFile file(log_filename);
    QFileDialog::getOpenFileName(this);


    if(!file.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::warning(this,"Warning", "Error during file loading");

    QTextStream in(&file);
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
   // textarea->document()->setPlainText(in.readAll());
    QGuiApplication::restoreOverrideCursor();





}

void MainWindow::saveFile(){

    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    QSaveFile file(log_filename);

    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&file);
        //out<<textarea->document()->toPlainText();

        if(!file.commit()){
            QMessageBox::warning(this,"Warning", "Error during file saving");

        }

    }else{
        QMessageBox::warning(this,"Warning", "Error during file opening");
    }
    QGuiApplication::restoreOverrideCursor();


}



void MainWindow::closeEvent(QCloseEvent *event){//Buttton close in alto a destra
     event->accept();
     //event->ignore(); //ignoro l'evento di chiusura se si clicca su "Cancel" dopo che ho modificato il file

}

void MainWindow::exit(){
    QApplication::quit();

}

void MainWindow::init_menubar(){
    fileMenu=menuBar()->addMenu("File");

    openAction=new QAction(QIcon(),"Open");
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip("Open a existing file");
    fileMenu->addAction(openAction);

    saveAction=new QAction(QIcon(),"Save");
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip("Save file");
    fileMenu->addAction(saveAction);

    fileMenu->addSeparator();
    exitAction=new QAction(QIcon(), "Exit");
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip("Exit program");
    fileMenu->addAction(exitAction);
}

MainWindow::~MainWindow(){
    delete fileMenu;
    delete openAction;
    delete saveAction;
    delete exitAction;
    delete directory;
    delete ui;
}



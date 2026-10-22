#include "mainwindow.h"

#include <QAction>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Конвертер валют"));
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    resize(START_WIDTH, START_HEIGHT);

    createActions();
    createMenus();
    createToolBar();
    createStatusBar();
}

void MainWindow::createActions()
{
    // Родитель this => действия удалятся вместе с окном
    m_newAction = new QAction(tr("&Новая конвертация"), this);
    connect(m_newAction, &QAction::triggered, this, &MainWindow::onNew);

    m_quitAction = new QAction(tr("&Выход"), this);
    connect(m_quitAction, &QAction::triggered, this, &QWidget::close);

    m_refreshAction = new QAction(tr("&Обновить курсы"), this);
    connect(m_refreshAction, &QAction::triggered,
            this, &MainWindow::onRefreshRates);

    m_aboutAction = new QAction(tr("&О программе"), this);
    connect(m_aboutAction, &QAction::triggered, this, &MainWindow::onAbout);
}

void MainWindow::createMenus()
{
    // menuBar()->addMenu() создаёт меню с родителем menuBar
    QMenu *fileMenu = menuBar()->addMenu(tr("&Файл"));
    fileMenu->addAction(m_newAction);
    fileMenu->addSeparator();
    fileMenu->addAction(m_quitAction);

    QMenu *ratesMenu = menuBar()->addMenu(tr("&Курсы"));
    ratesMenu->addAction(m_refreshAction);

    QMenu *helpMenu = menuBar()->addMenu(tr("&Справка"));
    helpMenu->addAction(m_aboutAction);
}

void MainWindow::createToolBar()
{
    // addToolBar() создаёт панель с родителем this
    QToolBar *toolBar = addToolBar(tr("Основная"));
    toolBar->setObjectName("MainToolBar");
    toolBar->addAction(m_newAction);
    toolBar->addAction(m_refreshAction);
}

void MainWindow::createStatusBar()
{
    // Постоянная надпись справа, временные сообщения показываются слева
    auto *info = new QLabel(tr("Курсы: не загружены"), this);
    statusBar()->addPermanentWidget(info);
    statusBar()->showMessage(tr("Готово"), STATUS_TIMEOUT_MS);
}

void MainWindow::onNew()
{
    statusBar()->showMessage(tr("Новая конвертация"), STATUS_TIMEOUT_MS);
}

// Заглушка: загрузка курсов появится на этапе 5
void MainWindow::onRefreshRates()
{
    statusBar()->showMessage(tr("Загрузка курсов будет добавлена позже"),
                             STATUS_TIMEOUT_MS);
}

void MainWindow::onAbout()
{
    QMessageBox::about(this, tr("О программе"),
                       tr("Конвертер валют v0.1\nКурсы ЦБ РФ.\nСквозной проект, Qt + C++17."));
}
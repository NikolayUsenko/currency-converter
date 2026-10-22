#include "mainwindow.h"

#include <QAction>
#include <QMessageBox>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Конвертер валют"));
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    resize(START_WIDTH, START_HEIGHT);

    createActions();
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
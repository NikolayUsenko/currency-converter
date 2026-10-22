#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;

/**
 * @brief Главное окно приложения «Конвертер валют».
 *
 * Содержит меню, панель инструментов и статус-бар.
 * Все объекты создаются с родителем (владелец: MainWindow).
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onNew();
    void onRefreshRates();
    void onAbout();

private:
    void createActions();
    void createMenus();
    void createToolBar();
    void createStatusBar();
    void createCentralWidget();

    static constexpr int STATUS_TIMEOUT_MS = 3000;
    static constexpr int MIN_WIDTH = 480;
    static constexpr int MIN_HEIGHT = 360;
    static constexpr int START_WIDTH = 640;
    static constexpr int START_HEIGHT = 420;

    QAction *m_newAction = nullptr;
    QAction *m_quitAction = nullptr;
    QAction *m_refreshAction = nullptr;
    QAction *m_aboutAction = nullptr;
};

#endif // MAINWINDOW_H
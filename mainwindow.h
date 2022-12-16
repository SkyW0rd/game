#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QTimer>
#include "game.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent*) override;
    void initLabels();
    void playAction();
    void backToMenu();
    void settingsAction();
    void exitAction();
    //void giveAction();
    void fullScreenAction();
private slots:
    void update_score();
private:
    Ui::MainWindow *ui;
    QLabel *score, *win_label, *lose_label;
    QTimer *score_timer;
    Game *game;
    bool clickedFullScreen = false;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QTimer>
#include "game.h"
#include <QDebug>
#include <QKeySequenceEdit>
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
    void WChange();
    void AChange();
    void SChange();
    void DChange();
    void fullScreenAction();
private slots:
    void update_score();
private:
    Ui::MainWindow *ui;
    QLabel *score, *win_label, *lose_label;
    QTimer *score_timer;
    Game *game;
    bool clickedFullScreen = false;
    int W = Qt::Key_W;
    int A = Qt::Key_A;
    int S = Qt::Key_S;
    int D = Qt::Key_D;
    bool trueGame = false;
};
#endif // MAINWINDOW_H

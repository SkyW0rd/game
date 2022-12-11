#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Zombies at home"));
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btnPlay, &QPushButton::clicked, this, &MainWindow::playAction);
    connect(ui->btnSettings, &QPushButton::clicked, this, &MainWindow::settingsAction);
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::exitAction);
    connect(ui->btnBack, &QPushButton::clicked, this, &MainWindow::backToMenu);
    connect(ui->btnBack2, &QPushButton::clicked, this, &MainWindow::backToMenu);
    connect(ui->btnGiveAction, &QPushButton::clicked, this, &MainWindow::giveAction);
    connect(ui->btnFullScreen, &QRadioButton::clicked, this, &MainWindow::fullScreenAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::fullScreenAction()
{
    if(clickedFullScreen == false)
    {
        MainWindow::showFullScreen();
        clickedFullScreen = true;
    }
    else
    {
        MainWindow::showNormal();
        clickedFullScreen = false;
    }
}
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(ui->stackedWidget->currentIndex() == 1 && game->stat != Game::Question)
    {
        //if(game->action != 0)
        //{
            switch(e->key())
            {
            case Qt::Key_W:
                game->player->player_move_up();
                game->action--;
                ui->label->setText(QString::number(game->action));
                break;
            case Qt::Key_A:
                game->player->player_move_left();
                game->action--;
                ui->label->setText(QString::number(game->action));
                break;
            case Qt::Key_S:
                game->player->player_move_down();
                game->action--;
                ui->label->setText(QString::number(game->action));
                break;
            case Qt::Key_D:
                game->player->player_move_right();
                game->action--;
                ui->label->setText(QString::number(game->action));
                break;
            }
        //}
        /*else
        {
            QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Action", "Do u need action?", QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                giveAction();
            }
            else
            {
                QMessageBox::warning(this, "Action", "PLEASE, TAKE ACTION!!!");
            }
        }*/
    }
}
void MainWindow::update_score()
{
    if(game->stat == Game::Win)
    {
        QMessageBox::about(this,"WIN LABEL","You Win!");
        score_timer->stop();
        game->stat = Game::Pause;
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if(game->stat == Game::Lose)
    {
        QMessageBox::about(this,"Lose Lable","You Lose!");
        score_timer->stop();
        game->stat = Game::Pause;
        ui->stackedWidget->setCurrentIndex(0);
    }

}
void MainWindow::initLabels()
{
    win_label = new QLabel(this);
    win_label->hide();
    win_label->setText("You win!");
    win_label->setStyleSheet("QLabel {font-family: Fixedsys;color: yellow;font-size: 16px;}");
    win_label->setGeometry(500,12,150,26);

    score_timer = new QTimer(this);
    score_timer->start(25);
    score_timer->start(25);
    connect(score_timer, SIGNAL(timeout()), this, SLOT(update_score()));

    score = new QLabel(this);
    score->setIndent(-80);
    score->setText("0");
    score->setStyleSheet("QLabel {font-family: Fixedsys;color: black;font-size: 16px;}");
    score->setGeometry(500,12,150,26);
}
void MainWindow::playAction()
{
    //qDebug() << game->player->vecIn.size();
    ui->stackedWidget->setCurrentIndex(1);
    ui->graphicsView->setStyleSheet("QGraphicsView {boreder: none;}");
    ui->graphicsView->setBackgroundBrush(Qt::gray);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);

    int map_height = 16, map_width = 27;
    int x = 0, y = 0;
    int w = (map_width * GameObject::Width);
    int h = (map_height * GameObject::Width);
    ui->graphicsView->setGeometry(x, y, w, h);
    game = new Game(x, y, map_width, map_height, ":/map.txt");
    ui->graphicsView->setScene(game);
    score = new QLabel(this);
    win_label =  new QLabel(this);
    lose_label = new QLabel(this);
    score_timer = new QTimer(this);

    initLabels();
    game->start();
}
void MainWindow::backToMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::settingsAction()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::exitAction()
{
    close();
}
void MainWindow::giveAction()
{
    if(game->action == 0)
    {
        int num = game->giveAction();
        game->action = num;
        ui->label->setText(QString::number(num));
    }
    else
    {
        QMessageBox::warning(this, "ACHTUNG", "U have action:  " + QString::number(game->action));
    }
}

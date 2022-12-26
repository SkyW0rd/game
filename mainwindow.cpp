#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Zombies at home"));
    setWindowFlag(Qt::FramelessWindowHint);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btnPlay, &QPushButton::clicked, this, &MainWindow::playAction);
    connect(ui->btnSettings, &QPushButton::clicked, this, &MainWindow::settingsAction);
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::exitAction);
    connect(ui->btnBack, &QPushButton::clicked, this, &MainWindow::backToMenu);
    connect(ui->btnFullScreen, &QRadioButton::clicked, this, &MainWindow::fullScreenAction);
    connect(ui->WKey, &QKeySequenceEdit::keySequenceChanged, this, &MainWindow::WChange);
    connect(ui->AKey, &QKeySequenceEdit::keySequenceChanged, this, &MainWindow::AChange);
    connect(ui->SKey, &QKeySequenceEdit::keySequenceChanged, this, &MainWindow::SChange);
    connect(ui->DKey, &QKeySequenceEdit::keySequenceChanged, this, &MainWindow::DChange);
    ui->WEditLine->setText("W");
    ui->AEditLine->setText("A");
    ui->SEditLine->setText("S");
    ui->DEditLine->setText("D");
    ui->WEditLine->setReadOnly(true);
    ui->AEditLine->setReadOnly(true);
    ui->SEditLine->setReadOnly(true);
    ui->DEditLine->setReadOnly(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::WChange()
{
    W = ui->WKey->keySequence()[0];
    ui->WEditLine->setText(QString("%1").arg(QChar(W)) + " Up");
}
void MainWindow::AChange()
{
    A = ui->AKey->keySequence()[0];
    ui->AEditLine->setText(QString("%1").arg(QChar(A)) + " Left");
}
void MainWindow::SChange()
{
    S = ui->SKey->keySequence()[0];
    ui->SEditLine->setText(QString("%1").arg(QChar(S)) + " Down");
}
void MainWindow::DChange()
{
    D = ui->DKey->keySequence()[0];
    ui->DEditLine->setText(QString("%1").arg(QChar(D)) + " Right");
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
    if(ui->stackedWidget->currentIndex() == 1 && game->stat != Game::Question && game->stat != Game::MiniGame)
    {
        //qDebug() << game->vecZombie.size();
        if(game->actionPlayer == 3 && !game->vecZombie.empty())
        {
            for(int i = 0; i < game->vecZombie.size(); i++)
            {
                game->ticket->cards[game->vecZombie[i][0]][game->vecZombie[i][1]]->move(i);
            }
            game->actionPlayer = 0;
        }
        //qDebug() <<"Pressed: " << e->key();
        //qDebug() << "W: " << W;
        if(e->key() == W)
        {
            game->player->player_move_up();
            if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
            {
                game->actionPlayer++;
            }
        }
        else if(e->key() == A)
        {
            game->player->player_move_left();
            if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
            {
                game->actionPlayer++;
            }
        }
        else if(e->key() == S)
        {
            game->player->player_move_down();
            if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
            {
                game->actionPlayer++;
            }
        }
        else if(e->key() == D)
        {
            game->player->player_move_right();
            if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
            {
                game->actionPlayer++;
            }
        }
        /*switch(e->key())
        {
            case Qt::Key_W:
                game->player->player_move_up();
                if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
                {
                    game->actionPlayer++;
                }
                break;
            case Qt::Key_A:
                game->player->player_move_left();
                if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
                {
                    game->actionPlayer++;
                }
                break;
            case Qt::Key_S:
                game->player->player_move_down();
                if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
                {
                    game->actionPlayer++;
                }
                break;
            case Qt::Key_D:
                game->player->player_move_right();
                if(!game->vecZombie.empty() && game->stat != Game::Question && game->stat != Game::MiniGame)
                {
                    game->actionPlayer++;
                }
                break;
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
        //game->~Game();
    }
    else if(game->stat == Game::Lose)
    {
        QMessageBox::about(this,"Lose Lable","You Lose!");
        score_timer->stop();
        game->stat = Game::Pause;
        ui->stackedWidget->setCurrentIndex(0);
        //game->~Game();
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
    if(trueGame == false)
    {
        game = new Game(x, y, map_width, map_height, ":/map.txt");
    }
    else
    {
        delete game;
        game = new Game(x, y, map_width, map_height, ":/map.txt");
        trueGame = true;
    }
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
/*void MainWindow::giveAction()
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
}*/

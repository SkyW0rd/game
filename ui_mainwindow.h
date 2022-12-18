/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_3;
    QPushButton *btnPlay;
    QPushButton *btnExit;
    QPushButton *btnSettings;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QWidget *page_3;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnBack;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *btnFullScreen;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(921, 606);
        MainWindow->setStyleSheet(QStringLiteral("border-image: url(:/image/1616042210_20-p-pikselnii-fon-dlya-igri-22.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_4 = new QGridLayout(page);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btnPlay = new QPushButton(page);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
        btnPlay->setSizePolicy(sizePolicy);
        btnPlay->setMinimumSize(QSize(200, 40));
        btnPlay->setStyleSheet(QStringLiteral("border-image: url(:/image/buttonPlay.png);"));

        gridLayout_3->addWidget(btnPlay, 0, 0, 1, 1);

        btnExit = new QPushButton(page);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        btnExit->setMinimumSize(QSize(200, 40));
        btnExit->setStyleSheet(QStringLiteral("border-image: url(:/image/btnExit.png);"));

        gridLayout_3->addWidget(btnExit, 2, 0, 1, 1);

        btnSettings = new QPushButton(page);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSettings->sizePolicy().hasHeightForWidth());
        btnSettings->setSizePolicy(sizePolicy1);
        btnSettings->setMinimumSize(QSize(200, 40));
        btnSettings->setStyleSheet(QStringLiteral("border-image: url(:/image/btnSettings.png);"));

        gridLayout_3->addWidget(btnSettings, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 1, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView = new QGraphicsView(page_2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_7 = new QGridLayout(page_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        btnBack = new QPushButton(page_3);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setMinimumSize(QSize(200, 40));
        btnBack->setStyleSheet(QStringLiteral("border-image: url(:/image/air.png);"));

        horizontalLayout_5->addWidget(btnBack);


        gridLayout_6->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btnFullScreen = new QRadioButton(page_3);
        btnFullScreen->setObjectName(QStringLiteral("btnFullScreen"));

        horizontalLayout_6->addWidget(btnFullScreen);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        gridLayout_6->addLayout(horizontalLayout_6, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnPlay->setText(QString());
        btnExit->setText(QString());
        btnSettings->setText(QString());
        btnBack->setText(QApplication::translate("MainWindow", "back", nullptr));
        btnFullScreen->setText(QApplication::translate("MainWindow", "Full Screan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

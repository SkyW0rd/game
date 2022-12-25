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
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLineEdit>
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
    QHBoxLayout *horizontalLayout;
    QKeySequenceEdit *WKey;
    QLineEdit *WEditLine;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QKeySequenceEdit *AKey;
    QLineEdit *AEditLine;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QKeySequenceEdit *SKey;
    QLineEdit *SEditLine;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QKeySequenceEdit *DKey;
    QLineEdit *DEditLine;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(921, 606);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(30);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QStringLiteral(""));
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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
        btnPlay->setSizePolicy(sizePolicy1);
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
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnSettings->sizePolicy().hasHeightForWidth());
        btnSettings->setSizePolicy(sizePolicy2);
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
        btnBack->setStyleSheet(QStringLiteral(""));

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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        WKey = new QKeySequenceEdit(page_3);
        WKey->setObjectName(QStringLiteral("WKey"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(WKey->sizePolicy().hasHeightForWidth());
        WKey->setSizePolicy(sizePolicy3);
        WKey->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(WKey);

        WEditLine = new QLineEdit(page_3);
        WEditLine->setObjectName(QStringLiteral("WEditLine"));
        sizePolicy3.setHeightForWidth(WEditLine->sizePolicy().hasHeightForWidth());
        WEditLine->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(WEditLine);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        gridLayout_6->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        AKey = new QKeySequenceEdit(page_3);
        AKey->setObjectName(QStringLiteral("AKey"));
        sizePolicy3.setHeightForWidth(AKey->sizePolicy().hasHeightForWidth());
        AKey->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(AKey);

        AEditLine = new QLineEdit(page_3);
        AEditLine->setObjectName(QStringLiteral("AEditLine"));
        sizePolicy3.setHeightForWidth(AEditLine->sizePolicy().hasHeightForWidth());
        AEditLine->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(AEditLine);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_6->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        SKey = new QKeySequenceEdit(page_3);
        SKey->setObjectName(QStringLiteral("SKey"));
        sizePolicy3.setHeightForWidth(SKey->sizePolicy().hasHeightForWidth());
        SKey->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(SKey);

        SEditLine = new QLineEdit(page_3);
        SEditLine->setObjectName(QStringLiteral("SEditLine"));
        sizePolicy3.setHeightForWidth(SEditLine->sizePolicy().hasHeightForWidth());
        SEditLine->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(SEditLine);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_6->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        DKey = new QKeySequenceEdit(page_3);
        DKey->setObjectName(QStringLiteral("DKey"));
        sizePolicy3.setHeightForWidth(DKey->sizePolicy().hasHeightForWidth());
        DKey->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(DKey);

        DEditLine = new QLineEdit(page_3);
        DEditLine->setObjectName(QStringLiteral("DEditLine"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DEditLine->sizePolicy().hasHeightForWidth());
        DEditLine->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(DEditLine);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        gridLayout_6->addLayout(horizontalLayout_4, 5, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


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

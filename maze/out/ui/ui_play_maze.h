/********************************************************************************
** Form generated from reading UI file 'play_maze.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_MAZE_H
#define UI_PLAY_MAZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_play_maze
{
public:
    QWidget *widget;
    QPushButton *creat_maze;
    QPushButton *DFS;
    QPushButton *save_maze;
    QPushButton *add_maze;
    QPushButton *no_path;
    QLabel *timer_label;

    void setupUi(QWidget *play_maze)
    {
        if (play_maze->objectName().isEmpty())
            play_maze->setObjectName(QString::fromUtf8("play_maze"));
        play_maze->resize(798, 659);
        play_maze->setMouseTracking(false);
        play_maze->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        widget = new QWidget(play_maze);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(660, 0, 141, 652));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(84, 84, 84);"));
        creat_maze = new QPushButton(widget);
        creat_maze->setObjectName(QString::fromUtf8("creat_maze"));
        creat_maze->setGeometry(QRect(20, 350, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \346\245\267\344\275\223 Std R"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        creat_maze->setFont(font);
        creat_maze->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"font: 12pt \"Adobe \346\245\267\344\275\223 Std R\";\n"
"background-color: rgb(255, 255, 255);"));
        DFS = new QPushButton(widget);
        DFS->setObjectName(QString::fromUtf8("DFS"));
        DFS->setGeometry(QRect(20, 260, 101, 41));
        DFS->setFont(font);
        DFS->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"font: 12pt \"Adobe \346\245\267\344\275\223 Std R\";\n"
"background-color: rgb(255, 255, 255);"));
        save_maze = new QPushButton(widget);
        save_maze->setObjectName(QString::fromUtf8("save_maze"));
        save_maze->setGeometry(QRect(20, 440, 101, 41));
        save_maze->setFont(font);
        save_maze->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"font: 12pt \"Adobe \346\245\267\344\275\223 Std R\";\n"
"background-color: rgb(255, 255, 255);"));
        add_maze = new QPushButton(widget);
        add_maze->setObjectName(QString::fromUtf8("add_maze"));
        add_maze->setGeometry(QRect(20, 530, 101, 41));
        add_maze->setFont(font);
        add_maze->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"font: 12pt \"Adobe \346\245\267\344\275\223 Std R\";\n"
"background-color: rgb(255, 255, 255);"));
        no_path = new QPushButton(widget);
        no_path->setObjectName(QString::fromUtf8("no_path"));
        no_path->setGeometry(QRect(20, 170, 101, 41));
        no_path->setFont(font);
        no_path->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"font: 12pt \"Adobe \346\245\267\344\275\223 Std R\";\n"
"background-color: rgb(255, 255, 255);"));
        timer_label = new QLabel(widget);
        timer_label->setObjectName(QString::fromUtf8("timer_label"));
        timer_label->setGeometry(QRect(10, 60, 121, 41));
        timer_label->setStyleSheet(QString::fromUtf8("font: 12pt \"Adobe \346\245\267\344\275\223 Std R\";\n"
"color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        retranslateUi(play_maze);

        QMetaObject::connectSlotsByName(play_maze);
    } // setupUi

    void retranslateUi(QWidget *play_maze)
    {
        play_maze->setWindowTitle(QCoreApplication::translate("play_maze", "\350\277\267\345\256\253\346\270\270\346\210\217", nullptr));
        creat_maze->setText(QCoreApplication::translate("play_maze", "\347\224\237\346\210\220\350\277\267\345\256\253", nullptr));
        DFS->setText(QCoreApplication::translate("play_maze", "\350\207\252\345\212\250\345\257\273\350\267\257", nullptr));
        save_maze->setText(QCoreApplication::translate("play_maze", "\344\277\235\345\255\230\350\277\267\345\256\253", nullptr));
        add_maze->setText(QCoreApplication::translate("play_maze", "\345\212\240\350\275\275\350\277\267\345\256\253", nullptr));
        no_path->setText(QCoreApplication::translate("play_maze", "\346\262\241\346\234\211\351\200\232\350\267\257", nullptr));
        timer_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class play_maze: public Ui_play_maze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_MAZE_H

#ifndef PLAY_MAZE_H
#define PLAY_MAZE_H

#include <QDialog>
#include "qpainter.h"
#include <QKeyEvent>
#include <QWidget>
#include <QQueue>
#include <QVector>
#include <QMessageBox>
#include <QStack>
#include <stdlib.h>
#include <time.h>
#include "point.h"
#include <math.h>
#include <QtAlgorithms>
#include <QTimer>
#include <QDesktopWidget>
#include <QTime>
#include <stack.h>

//using namespace std;

namespace Ui {
class play_maze;
}

class play_maze : public QWidget
{
    Q_OBJECT

public:
    explicit play_maze(QWidget *parent = nullptr);
    ~play_maze();

private slots:
    void on_creat_maze_clicked();    
    
    void on_DFS_clicked();

    void on_no_path_clicked();

    void on_save_maze_clicked();

    void on_add_maze_clicked();

    void TimerDispaly();

private:
    Ui::play_maze *ui;

    int maze_row = 25;  //迷宫行数
    int maze_col = 25;  //迷宫列数
    bool flag_success=false;//完成后不进行搜
    bool flag_has_path=false;

    int W;
    int H;//界面宽度和高度
    int maze_cell_size;//每个块的大小

    point maze[25][25];//迷宫
    bool creat_maze=false;

    int control_X;
    int control_Y;//控制点的位置
    int target_X;
    int target_Y;//目标点位置
    int target_X2;
    int target_Y2;//鼠标点击位置坐标

    int control_direction;//控制点行走的方向,1,2分别代表左右
    int pre_control_direction;
    
    QPixmap control_RIGHT;
    QPixmap control_LEFT;
    QPixmap target;//目标图片
    QPixmap wall;//墙
    QPixmap road;//路

    QTimer *timer;//定时器
    int sec;

    int graph[25][25];//用于标记是否被搜索过

    QStack<point> DFS_search;//用于深度优先搜索的栈
    QVector<point> auto_path;//自动寻路用

    QStack<point> build_maze_stack;//创建迷宫的栈
    point path[25][25];//用于搜索路径的矩阵

    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);    
};

#endif // PLAY_MAZE_H

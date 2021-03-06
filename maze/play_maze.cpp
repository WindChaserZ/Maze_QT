#include "play_maze.h"
#include "ui_play_maze.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

//using namespace std;

play_maze::play_maze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::play_maze)
{
    ui->setupUi(this);
    on_creat_maze_clicked();
    control_direction=2;//往右
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint); // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);
    control_LEFT.load(":img/img/control_left.jpg");
    control_RIGHT.load(":img/img/control_right.jpg");
    target.load(":img/img/target.jpg");
    road.load(":img/img/road.jpg");
    wall.load(":img/img/wall.jpg");   
    sec = 600;
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &play_maze::TimerDispaly);
}

play_maze::~play_maze()
{
    delete ui;
}

void play_maze::on_creat_maze_clicked()//创建迷宫
{
    flag_success=false;
    //获取行列值
    control_X=1;
    control_Y=1;
    target_X=maze_row-3;
    target_Y=maze_col-3;

    for(int i=0;i<maze_row;i++){
        for(int j=0;j<maze_col;j++){
            maze[i][j].i=i;
            maze[i][j].j=j;
            maze[i][j].state=0;
        }
    }
    int max;
    if(maze_row>=maze_col)
        max=maze_row;
    else
        max=maze_col;

    maze_cell_size=650/max;

    build_maze_stack.clear();

    int i=3,j=3;
    maze[i][j].state=1;

    point temp;
    temp.i=i;
    temp.j=j;
    temp.state=1;
    bool up=false,down=false,left=false,right=false;

    srand((unsigned)time(NULL));

    while(true){//利用prim算法生成迷宫
        temp.i=i;
        temp.j=j;

        int randnum=rand()%4;

        switch (randnum) {
        case 0: if(!up&&i>2&&maze[i-2][j].state==0){
                build_maze_stack.push(temp);
                maze[i-2][j].state=1;
                maze[i-1][j].state=1;
                i=i-2;
                if(maze[i-1][j].state==0)
                    up=false;
                else
                    up=true;
                if(maze[i+1][j].state==0)
                    down=false;
                else
                    down=true;
                if(maze[i][j-1].state==0)
                    left=false;
                else
                    left=true;
                if(maze[i][j+1].state==0)
                    right=false;
                else
                    right=true;
            }
            else{
                up=true;
            }
            break;
        case 1: if(!down&&i<maze_row-3&&maze[i+2][j].state==0)
            {
                build_maze_stack.push(temp);
                maze[i+2][j].state=1;
                maze[i+1][j].state=1;
                i=i+2;
                if(maze[i-1][j].state==0)
                    up=false;
                else
                    up=true;
                if(maze[i+1][j].state==0)
                    down=false;
                else
                    down=true;
                if(maze[i][j-1].state==0)
                    left=false;
                else
                    left=true;
                if(maze[i][j+1].state==0)
                    right=false;
                else
                    right=true;
            }
            else{
                down=true;
            }
            break;
        case 2: if(!left&&j>2&&maze[i][j-2].state==0)
            {
                build_maze_stack.push(temp);
                maze[i][j-2].state=1;
                maze[i][j-1].state=1;
                j=j-2;
                if(maze[i-1][j].state==0)
                    up=false;
                else
                    up=true;
                if(maze[i+1][j].state==0)
                    down=false;
                else
                    down=true;
                if(maze[i][j-1].state==0)
                    left=false;
                else
                    left=true;
                if(maze[i][j+1].state==0)
                    right=false;
                else
                    right=true;
            }
            else{
                left=true;
            }
            break;
        case 3: if(!right&&j<maze_col-3&&maze[i][j+2].state==0)
            {
                build_maze_stack.push(temp);
                maze[i][j+2].state=1;
                maze[i][j+1].state=1;
                j=j+2;
                if(maze[i-1][j].state==0)
                    up=false;
                else
                    up=true;
                if(maze[i+1][j].state==0)
                    down=false;
                else
                    down=true;
                if(maze[i][j-1].state==0)
                    left=false;
                else
                    left=true;
                if(maze[i][j+1].state==0)
                    right=false;
                else
                    right=true;
            }
            else{
                right=true;
            }
            break;
        }
        if(up&&down&&left&&right){
            if(!build_maze_stack.isEmpty()){
                i=build_maze_stack.top().i;
                j=build_maze_stack.top().j;
                build_maze_stack.pop();
                if(maze[i-1][j].state==0)
                    up=false;
                else
                    up=true;
                if(maze[i+1][j].state==0)
                    down=false;
                else
                    down=true;
                if(maze[i][j-1].state==0)
                    left=false;
                else
                    left=true;
                if(maze[i][j+1].state==0)
                    right=false;
                else
                    right=true;
            }
            else{
                maze[1][1].state=2;
                maze[maze_row-3][maze_col-3].state=3;
                //随机放置障碍，制造无法生成通路
                maze[rand()%20][rand()%18].state=0;
                creat_maze=true;
                for(int i=0; i<maze_row; i++)
                    for(int j=0; j<maze_col; j++){
                        path[i][j].state=0;
                        path[i][j].i=i;
                        path[i][j].j=j;
                    }
                return;
            }
        }
    }
}

void play_maze::on_DFS_clicked()//深度优先搜索
{
    flag_has_path = false;
    if(!creat_maze){
        return;
    }

    DFS_search.clear();

    for(int i=0; i<maze_row; i++)
        for(int j=0; j<maze_col; j++){
            path[i][j].state=0;
            path[i][j].i=i;
            path[i][j].j=j;
        }
    //用于记录该点是否搜索的矩阵
    for(int i=0; i<maze_row; i++)
        for(int j=0; j<maze_col; j++){
            if(maze[i][j].state==0)
                graph[i][j]=1;
            else
                graph[i][j]=0;//初始化未被搜索
        }

    QString message;
    int searchnum=0;//搜索节点次数
    point top;
    top.i=control_X;
    top.j=control_Y;
    top.state=0;
    DFS_search.push(top);

    while(!DFS_search.isEmpty()){
        top=DFS_search.top();
        qDebug()<<top.i<<" "<<top.j<<" "<<top.state<<endl;

        if(graph[top.i][top.j]==0){
            searchnum+=1;
            if(maze[top.i][top.j].state==3){
                flag_has_path = true;
                break;
            }
        }
        //将未访问的子节点放入开节点表
        if((graph[top.i-1][top.j]==0)&&(maze[top.i-1][top.j].state!=0)){
            DFS_search.push(point(top.i-1,top.j,0));
            path[top.i-1][top.j].state=2;
        }
        else if((graph[top.i+1][top.j]==0)&&(maze[top.i+1][top.j].state!=0)){
            DFS_search.push(point(top.i+1,top.j,0));
            path[top.i+1][top.j].state=1;
        }
        else if((graph[top.i][top.j+1]==0)&&(maze[top.i][top.j+1].state!=0)){
            DFS_search.push(point(top.i,top.j+1,0));
            path[top.i][top.j+1].state=3;
        }
        else if((graph[top.i][top.j-1]==0)&&(maze[top.i][top.j-1].state!=0)){
            DFS_search.push_back(point(top.i,top.j-1,0));
            path[top.i][top.j-1].state=4;
        }
        else{
            DFS_search.pop();
        }

        //将此点标记为访问过
        graph[top.i][top.j]=1;
    }
}

bool cmp(point &a,point &b){//为了实现qsort函数的排序
    return a.state<b.state;
}

void play_maze::keyPressEvent(QKeyEvent *event){//控制移动
    timer->start(1000);
    switch (event->key()) {
    case Qt::Key_W: if((control_Y>0)&&((maze[control_X][control_Y-1].state==1)||(maze[control_X][control_Y-1].state==3))){
            path[control_X][control_Y-1].state=0;//这一段是防止到达终点依旧显示路线
            maze[control_X][control_Y-1].state=2;
            maze[control_X][control_Y].state=1;
            control_Y-=1;
        }
        break;
    case Qt::Key_S: if((control_Y<maze_col-1)&&((maze[control_X][control_Y+1].state==1)||(maze[control_X][control_Y+1].state==3))){
            path[control_X][control_Y+1].state=0;
            maze[control_X][control_Y+1].state=2;
            maze[control_X][control_Y].state=1;
            control_Y+=1;
        }
        break;
    case Qt::Key_A: if((control_X>0)&&((maze[control_X-1][control_Y].state==1)||(maze[control_X-1][control_Y].state==3))){
            path[control_X-1][control_Y].state=0;
            maze[control_X-1][control_Y].state=2;
            maze[control_X][control_Y].state=1;
            control_X-=1;
            control_direction=1;
        }
        break;
    case Qt::Key_D: if((control_X<maze_row-1)&&((maze[control_X+1][control_Y].state==1)||(maze[control_X+1][control_Y].state==3))){
            path[control_X+1][control_Y].state=0;
            maze[control_X+1][control_Y].state=2;
            maze[control_X][control_Y].state=1;
            control_X+=1;
            control_direction=2;
        }
        break;
        //目标移动
    case Qt::Key_I: if((target_Y>0)&&((maze[target_X][target_Y-1].state==1)&&((maze[target_X][target_Y].state!=2)))){
            maze[target_X][target_Y-1].state=3;
            maze[target_X][target_Y].state=1;
            target_Y-=1;
        }
        break;
    case Qt::Key_K: if((target_Y<maze_col-1)&&((maze[target_X][target_Y+1].state==1))&&((maze[target_X][target_Y].state!=2))){
            maze[target_X][target_Y+1].state=3;
            maze[target_X][target_Y].state=1;
            target_Y+=1;
        }
        break;
    case Qt::Key_J: if((target_X>0)&&((maze[target_X-1][target_Y].state==1))&&((maze[target_X][target_Y].state!=2))){
            maze[target_X-1][target_Y].state=3;
            maze[target_X][target_Y].state=1;
            target_X-=1;
        }
        break;
    case Qt::Key_L: if((target_X<maze_row-1)&&((maze[target_X+1][target_Y].state==1))&&((maze[target_X][target_Y].state!=2))){
            maze[target_X+1][target_Y].state=3;
            maze[target_X][target_Y].state=1;
            target_X+=1;
        }
        break;
    }
    if((control_X==target_X)&&(control_Y==target_Y)&&creat_maze){
        maze[target_X][target_Y].state=2;
        target_X=0;
        target_Y=0;
        maze[target_X][target_Y].state=0;
        flag_success=true;
        QMessageBox::information(NULL, QString::fromLocal8Bit("恭喜您"),  QString::fromLocal8Bit("挑战成功！"), QMessageBox::Yes, QMessageBox::Yes);
    }
}

void play_maze::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen Pen(Qt::blue);
    Pen.setWidth(8);
    for(int i=0;i<maze_row;i++){
        for(int j=0;j<maze_col;j++)
        {
            if(maze[i][j].state==0)
            {
                painter.drawPixmap(maze_cell_size*i+5,maze_cell_size*j+5,maze_cell_size,maze_cell_size,wall);
            }
            else if(maze[i][j].state==1)
            {
                painter.drawPixmap(maze_cell_size*i+5,maze_cell_size*j+5,maze_cell_size,maze_cell_size,road);
            }
            else if(maze[i][j].state==2)
            {
                if(control_direction==1)
                {
                   painter.drawPixmap(maze_cell_size*i+5,maze_cell_size*j+5,maze_cell_size,maze_cell_size,control_LEFT);
                }
                else
                {
                    painter.drawPixmap(maze_cell_size*i+5,maze_cell_size*j+5,maze_cell_size,maze_cell_size,control_RIGHT);
                }
            }
            else if(maze[i][j].state==3)
            {
                painter.drawPixmap(maze_cell_size*i+5,maze_cell_size*j+5,maze_cell_size,maze_cell_size,target);
            }
        }
        painter.setPen(Pen);
        point draw_point=path[target_X][target_Y];
        point pre_draw_point;
        while(draw_point.state!=0)
        {
            if(draw_point.i==control_X&&draw_point.j==control_Y)
                break;
            if(draw_point.state==1)//上
                pre_draw_point=path[draw_point.i-1][draw_point.j];
            if(draw_point.state==2)//下
                pre_draw_point=path[draw_point.i+1][draw_point.j];
            if(draw_point.state==3)//左
                pre_draw_point=path[draw_point.i][draw_point.j-1];
            if(draw_point.state==4)//右
                pre_draw_point=path[draw_point.i][draw_point.j+1];
            painter.drawLine(QPointF(maze_cell_size*draw_point.i+(maze_cell_size/2)+5,maze_cell_size*draw_point.j+(maze_cell_size/2)+5),QPointF(maze_cell_size*pre_draw_point.i+(maze_cell_size/2)+5,maze_cell_size*pre_draw_point.j+(maze_cell_size/2)+5));
            draw_point=pre_draw_point;
        }
        update();
     }
}

void play_maze::on_no_path_clicked()
{
    //判断是否有通路
    on_DFS_clicked();
    if(flag_has_path == true)
    {
        QMessageBox::information(NULL,  QString::fromLocal8Bit("很遗憾"),  QString::fromLocal8Bit("挑战失败，有通路！"), QMessageBox::Yes, QMessageBox::Yes);
    }
    else{
        QMessageBox::information(NULL, QString::fromLocal8Bit("恭喜您"),  QString::fromLocal8Bit("挑战成功！"), QMessageBox::Yes, QMessageBox::Yes);
    }
}

void play_maze::on_save_maze_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存迷宫"), "", tr("*.maze;"));
    if(filePath.isEmpty())
    {
        QMessageBox::information(NULL, QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("未输入文件名！"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    else
    {
        QFile mazeFile(filePath);
        mazeFile.open(QIODevice::ReadWrite);
        QTextStream writeStream(&mazeFile);
        for(int i = 0; i < 25; i ++)
        {
            for(int j = 0; j < 25; j ++)
            {
                writeStream << dec << maze[i][j].i << endl;
                writeStream << dec << maze[i][j].j << endl;
                writeStream << dec << maze[i][j].state << endl;
            }
        }
        mazeFile.close();
    }
}

void play_maze::on_add_maze_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("打开图片文件"), QCoreApplication::applicationDirPath(), "maze Files(*.maze);");
    if(filePath.isEmpty())
    {
        QMessageBox::information(NULL,  QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("未输入文件路径！"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    else
    {
        QFile mazeFile(filePath);
        mazeFile.open(QIODevice::ReadWrite);
        QTextStream readStream(&mazeFile);
        for(int i = 0; i < 25; i ++)
        {
            for(int j = 0; j < 25; j ++)
            {
                readStream >> maze[i][j].i >> maze[i][j].j >> maze[i][j].state;
            }
        }
        mazeFile.close();
    }
}

void play_maze::TimerDispaly()
{
    if(flag_success == true)
    {
        timer->stop();
        return;
    }
    sec --;
    if(sec == 0)
    {
        timer->stop();
        QMessageBox::information(NULL, QString::fromLocal8Bit("很遗憾"),QString::fromLocal8Bit("未在指定时间完成！"), QMessageBox::Yes, QMessageBox::Yes);
    }
    else
    {
        ui->timer_label->setText(QString::fromLocal8Bit("倒计时") + QString::number(sec));
    }
}

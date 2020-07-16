#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
    Stack(int size);   //分配内存初始化栈空间，设定栈容量，栈顶
    ~Stack();          //回收栈空间内存
    bool stackEmpty();   //判定栈是否为空，为空返回true，非空返回false
    bool stackFull();    //判定栈是否已满，为满返回true，不满返回false
    void clearStack();   //清空栈
    int stackLength();   //已有元素的个数
    bool push(T elem); //元素入栈，栈顶上升
    bool pop(T &elem); //元素出栈，栈顶下降
    void stackTraverse(bool ifFromBottom);  //遍历栈中所有元素
private:
    T *m_pBuffer; //栈空间指针
    int m_iSize;  //栈容量
    int m_iTop;  //栈顶，栈中元素个数
};

template <typename T>
Stack<T>::Stack(int size)
{
    m_iSize = size;
    m_pBuffer = new T[m_iSize];
    m_iTop = 0;
}
template <typename T>
Stack<T>::~Stack()
{
    delete[] m_pBuffer;
}
template <typename T>
bool Stack<T>::stackEmpty()
{
    return 0 == m_iTop ? true : false;
}
template <typename T>
bool Stack<T>::stackFull()
{
    return m_iTop == m_iSize ? true : false;
}
template <typename T>
void Stack<T>::clearStack()
{
    m_iTop = 0;
}
template <typename T>
int Stack<T>::stackLength()
{
    return m_iTop;
}
template <typename T>
bool Stack<T>::push(T elem)
{
    if (stackFull())
    {
        return false;
    }
    m_pBuffer[m_iTop] = elem;
    m_iTop++;
    return true;
}
template <typename T>
bool Stack<T>::pop(T & elem)
{
    if (stackEmpty())
    {
        return false;
    }
    m_iTop--;
    elem = m_pBuffer[m_iTop];
    return true;
}
template <typename T>
void Stack<T>::stackTraverse(bool ifFromBottom)
{
    if (ifFromBottom)
    {
        for (int i = 0; i < m_iTop; i++)
        {
            cout << m_pBuffer[i];
        }
    }
    else {
        for (int i = m_iTop - 1; i >= 0; i--)
        {
            m_pBuffer[i].printCoordinate();
        }
    }
}

#endif // STACK_H

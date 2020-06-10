//一维数组实现顺序存储结构
#include <iostream>
using namespace std;

/*存储空间分配初始分配量*/
#define MAXSIZE 20
/* ElemType类型根据实际情况而定，这里假设为int */
typedef int ElemType;

typedef struct
{
    /*数组存储数据元素，最大值为MAXSIZE*/
    ElemType data[MAXSIZE];
    /*线性表当前长度*/
    int length;
} SqList;

/*获取元素操作*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
/*
Status是函数的类型，其值是函数结果状态代码，如OK等
初始条件：顺序线性表L已存在，1<=i && i<=ListLength(L)
操作结果：用e返回L中第i个元素的值 
*/

Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

int main()
{
    SqList List;
    ElemType *p = new ElemType;
    List.length = 4;
    List.data[0] = 2;
    cout << GetElem(List, 1, p) << endl;
    delete p;
    return 0;
}
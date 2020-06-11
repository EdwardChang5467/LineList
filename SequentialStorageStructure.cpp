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

/*获取元素操作GetElem()*/
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

/*
插入元素操作ListInsert()

算法思路：
插入位置不合理则抛出异常；
线性表长度大于或等于数组长度，则抛出异常或动态增加容量；
从最后一个元素开始向前遍历到第 i 个位置，分别将他们向后移动一个位置；
将要插入元素填入位置 i 中；

初始条件：顺序线性表L已存在，1<=i && i<=ListInsert(L);
操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1；
*/

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    /* 顺序线性表已满 */
    if (L->length == MAXSIZE)
    {
        return ERROR;
    }
    /* 当i不在范围内时 */
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    /* 若插入数据的位置不在表尾 */
    if (i <= L->length)
    {
        /*将要插入位置后的数据元素向后移动一位*/
        for (k = L->length - 1; k >= i - 1; k--)
        {
            L->data[k + 1] = L->data[k];
        }
    }
    /*将新元素插入*/
    L->data[i - 1] = e;
    L->length++;
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
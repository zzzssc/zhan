#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int Position;
typedef struct SNode * PtrToSNode;
struct SNode{
    int * Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;


//顺序栈的创建
Stack CreateStack(int MaxSize){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (int *)malloc(MaxSize * sizeof(int));
    S->Top =-1;
    S->MaxSize=MaxSize;
    return S;
}

//顺序栈的入栈操作
bool  IsFull(Stack S)
{
    return (S->Top==S->MaxSize-1);
}
bool  Push(Stack S,int X)
{
    if(IsFull(S))
    {
        printf("堆栈满\n");
    }
    else
    {
        S->Data[++(S->Top)]=X;
        printf("入栈成功\n");
    }
}

//顺序栈的出栈操作
bool IsEmpty(Stack S)
{
    return(S->Top==-1);
}
int Pop(Stack S)
{
    if(IsEmpty(S)){
        printf("堆栈空\n");
    }
    else
        
        return (S->Data[(S->Top)--]);
    
}
int main(){
    //初始化堆栈
    Stack S = CreateStack(10);
    int i,n,z,p;
    //入栈
    printf("入栈个数为: ");
    scanf("%d",&n);
    printf("输入入栈元素: ");
    for(i=0;i<n;i++){
        scanf("%d",&z);
        Push(S,z);
    }
    printf("出栈顺序为: \n");
    //出栈
    while(!IsEmpty(S)){
        p = Pop(S);
        printf("出栈元素为%d\n",p);
    }
    
    return 0;
}

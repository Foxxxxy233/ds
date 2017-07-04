//
//  Header.h
//  Hw2-12
//
//  Created by 胡观宇 on 2017/3/29.
//  Copyright © 2017年 中传第一纯✌️. All rights reserved.
//

#ifndef Header_h
#define Header_h

typedef int ElemType;

typedef struct node //定义结点
{
    ElemType data; //结点的数据域
    struct node *next; //结点的指针域
}ListNode; //别名儿

typedef ListNode *LinkList; //LinkList就是一个指向结构体的指针

void CreateList(LinkList &L, int num);

void PrintList(LinkList &L);

void SortList(LinkList &L);

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc);



#endif /* Header_h */

//
//  main.cpp
//  Hw2-12
//
//  Created by 胡观宇 on 2017/3/29.
//  Copyright © 2017年 中传第一纯✌️. All rights reserved.
//



/*
   小胡同学啊可以说是很有诚意了！首先勇敢地选择自己先来做一做！
   那么就要分析一下这道题！有创建链表也有排序还有合并。
   我之前看的是很简单的合并题 我不会排序 怎么办。
   嗯 不知道 那看一眼书吧。
   大体上思路应该是：创建链表->随机产生数字填满->链表内部进行排序->两个链表进行合并->获得老师的鼓pi励ping
 
   啊 夜是那么黑 我才开始做！🎵夜是那么黑分不清悲喜界限 任谁都好累青春只剩一滴眼泪~
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Header.h"

void CreateList(LinkList &L, int num) //随机生成一无序链表
{
    int i;
    ListNode *p;
//LinkList &p; 这种为什么不行呢
//struct node *p; 可以
//ListNode &p; 也不行
    
    L = (LinkList)malloc(sizeof(ListNode));
    L->next = NULL; //先建立一个带头结点的单链表
    
    srand(time(NULL)); //这个东西必须要放在外面 不然就会产生一样的数据
    
    for(i = num; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(ListNode)); //生成新指针（指向即将建成的新结点）
        p->data = (int)rand() % 1024;
        
        p->next = L->next;
        L->next = p;
    }
    
}

void PrintList(LinkList &L)
{
    ListNode *a = L->next; //从第一个结点打印
    
    while(a->next)
    {
        printf("%d  ", a->data);
        a = a->next;
    }
    printf("%d", a->data); //最后一个数
    
    printf("\n");
}

void SortList(LinkList &L) //沉底儿法？？？呃忘了啥名儿了
{
    int fish;
    
    ListNode *m = L->next;
    ListNode *n;
    
    while(m)
    {
        n = m->next;
        
        while(n)
        {
            if(m->data > n->data)
            {
                fish = m->data;
                m->data = n->data;
                n->data = fish;
            }
            
            n = n->next;
        }
        
        m = m->next;
    }
}

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    ListNode *pa;
    ListNode *pb;
    ListNode *pc;
    
    pa = La->next;
    pb = Lb->next;
    
    Lc = pc = La; //用La的头结点作为Lc的头结点
    
    while(pa && pb)
    {
        if(pa->data > pb->data)
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        else
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
    }
    
    pc->next = pa ? pa : pb; //插入剩余段
    
    free(Lb); //释放多余的头结点（就剩一头结点了）
}


int main()
{
    ListNode *la;
    ListNode *lb;
    ListNode *lc;
    
    int a;
    int b;
    
    printf("请输入la链表中的数字个数：");
    scanf("%d", &a);
    printf("\n请输入lb链表中的数字个数：");
    scanf("%d", &b);
    printf("\n\n\n");
    
    CreateList(la, a);
    CreateList(lb, b);
    
    SortList(la);
    SortList(lb);
    
    printf("la: ");
    PrintList(la);
    printf("lb: ");
    PrintList(lb);
    printf("\n");
    
    MergeList(la, lb, lc);
    
    printf("lc: ");
    PrintList(lc);
    
    return 0;
    
}

// 第一次其实没算成功 但好歹也算是成功了！是吧！哈哈哈哈哈哈我还不会交到GitHub仓库呢哈哈哈哈哈哈哈哈😠
// 我好想 出去骑自行车！
// 哎呀烦死了我第二次作业还没看呢 人生好难啊！
















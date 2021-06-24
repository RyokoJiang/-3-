//
//  main.cpp
//  Suanfa_11
//
//  Created by 姜姜 on 2021/6/23.
//

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
const int n=8;//{5,5,10,10,10,15,20,25}
const int m=2*n-1;//节点总数
typedef struct{
    int weight;//权值
    int parent,lchild,rchild;//父节点、左孩子、右孩子
}Node;
typedef struct{
    int id;
    int weight;
}temp;
typedef Node HuffmanTree[MAX];

typedef struct{
    char bits[n+1];//存放编码位串
}CodeNode;
typedef CodeNode HuffmanCode[MAX];

//初始化
void InitTree(HuffmanTree T){
    for(int i=0;i<m;i++){
        T[i].weight=0;
        T[i].parent=-1;
        T[i].lchild=-1;
        T[i].rchild=-1;
    }
}
bool cmp(temp a,temp b){
    return a.weight<b.weight;
}
//选出最小和次小，记录序号和权值
void select(HuffmanTree T,int k,int *p1,int *p2){
    temp x[MAX];
    int i,j;
    for(i=0,j=0;i<=k;i++){
        if(T[i].parent==-1){
            x[j].id=i;
            x[j].weight=T[i].weight;
            j++;
        }
    }
    sort(x,x+j,cmp);
    *p1=x[0].id;
    *p2=x[1].id;
}
void CreateHuffmanTree(HuffmanTree T){
    int p1,p2;
    InitTree(T);
    T[0].weight=5;
    T[1].weight=5;
    T[2].weight=10;
    T[3].weight=10;
    T[4].weight=10;
    T[5].weight=15;
    T[6].weight=20;
    T[7].weight=25;
    
    for(int i=n;i<m;i++){
        select(T,i-1,&p1,&p2);
        T[p1].parent=T[p2].parent=i;
        T[i].lchild=p1;
        T[i].rchild=p2;
        T[i].weight=T[p1].weight+T[p2].weight;
    }
}

//根据哈夫曼树T求哈夫曼编码表H
void CharSetHuffmanEncoding(HuffmanTree T,HuffmanCode H){
    int c,p;//c和p分别是T中孩子和双亲的位置
    char cd[n+1];//临时存放编码
    int start;//指示编码在cd中的起始位置
    cd[n]='\0';//编码结束符
    
    
    for(int i=0;i<n;i++){
        start=n;
        c=i;
        while((p=T[c].parent)>=0){
            if(T[p].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
            c=p;
        }
        strcpy(H[i].bits,&cd[start]);//复制编码位串
    }
}
int main(){
    HuffmanTree T;
    CreateHuffmanTree(T);
    HuffmanCode H;
    CharSetHuffmanEncoding(T,H);
    int wpl=0;
    for(int i=0;i<n;i++){
        //cout<<"id:"<<i<<"    weight:"<<T[i].weight<<endl;
        cout<<T[i].weight<<":"<<H[i].bits<<endl;
        wpl+=strlen(H[i].bits)*T[i].weight;
    }
    cout<<"平均:"<<wpl*1.0/100;
    return 0;
}

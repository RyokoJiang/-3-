//
//  main.c
//  Search
//
//  Created by 姜姜 on 2021/3/22.
//  Copyright © 2021 JIang Yuqing. All rights reserved.
//

#include <stdio.h>
int SequentialSearch(int a[],int k,int total);
int BinarySearch(int a[],int k,int total);
int main() {
    // insert code here...
    int a[100]={0};
    int i=0,k,total;
    printf("请输入数组内的数字个数：");
    scanf("%d",&total);
    printf("请输入要查找的数字：");
    scanf("%d",&k);
//    printf("k=%d",k);
    printf("请输入数组:");
    for(;i<total;i++){
        scanf("%d",&a[i]);
    }
    printf("顺序查找的结果为%d\n",SequentialSearch(a, k, total));
    printf("二分查找的结果为%d",BinarySearch(a,k,i));
    return 0;
}
int SequentialSearch(int a[],int k,int total){
    int i=0;
    for(;i<total;i++){
        if(a[i]==k){
            return i+1;
        }
    }
    return -1;
}
int BinarySearch(int a[],int k,int total){
    int i=0,j=total-1;//j=total-1
    while(i<=j){
        int m=(i+j)/2;
        if(a[m]==k){
            return m+1;
        }
        else if(a[m]>k){
            j=m-1;
        }
        else{
            i=m+1;
        }
    }
    return -1;
}

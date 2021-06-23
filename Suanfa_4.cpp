//
//  main.cpp
//  Suanfa_4
//
//  Created by 姜姜 on 2021/6/23.
//

#include <iostream>

using namespace std;
const int N =1e5;
int n, a[N], tmp[N];
void merge(int a[],int left, int mid, int right,int tmp[]) {
    int startA = left, startB = mid + 1, pos=1;
    //归并的两段数组，pos为tmp数组中的下标
    while (startA <= mid && startB <= right) {
        if (a[startA] < a[startB]) //较小值存入tmp数组
            tmp[pos++]=a[startA++];
        else
            tmp[pos++] = a[startB++];
    }
    //剩余的数加在tmp后
    while (startA<=mid)
        tmp[pos++] = a[startA++];
    while (startB <= right)
        tmp[pos++] = a[startB++];
    //更新原数组为归并后内容
    pos = 1;
    for (int i = left; i <= right; i++)
        a[i] = tmp[pos++];
}

void mergeSort(int a[], int left, int right,int temp[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid, temp);                //分治思想的
        mergeSort(a, mid + 1, right, temp);
        merge(a, left, mid, right, temp);             //归并排序后的数据
    }
}

int main()
{
    cin>>n;  //输入数组个数
    for(int i=1;i<=n;i++) cin>>a[i];   //数字
    cout << "before：";
    for (int i = 1; i <= n; i++)  cout << a[i] << " ";
    cout << endl;
    mergeSort(a,1,n,tmp);
    cout << "after：";
    for (int i = 1; i <= n; i++)  cout << a[i] <<" ";  //输出结果
}

//
//  main.cpp
//  Suanfa_6
//
//  Created by 姜姜 on 2021/6/23.
//

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long select(int k,int* S,int num){
    int num1,num2,i,j,m,n1,n2,n3;
    int temp[5],M[2005],S1[10005],S2[10005],S3[10005];
    if(num <= 5){
        sort(S,S+num);
        return S[k-1];
    }
    else{
        num1 = num / 5;
        j = 0; num2 = 0;
        for(i=0;i<num1*5;i++){
            temp[j] = S[i];
            j++;
            if(j == 5){
                j = 0;
                sort(temp,temp+5);
                M[num2] = temp[2];
                num2++;
            }
        }
        m = select((num1 + 1) / 2,M,num2);
        n1 = n2 = n3 = 0;
        for(i=0;i<num;i++){
            if(S[i] < m){
                S1[n1] = S[i];
                n1++;
            }
            else if(S[i] == m){
                S2[n2] = S[i];
                n2++;
            }
            else{
                S3[n3] = S[i];
                n3++;
            }
        }
        if(n1 > k) return(select(k,S1,n1));
        else if(n1 + n2 >= k) return m;
        else return(select(k - n1 - n2,S3,n3));
    }
}
int a[10005];
int main(){
    int n,k,i,result;
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    cin >> k;
    result = select(k,a,n);
    cout << result << endl;
    return 0;
}

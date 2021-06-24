//
//  main.cpp
//  Suanfa_9
//
//  Created by 姜姜 on 2021/6/23.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e3+10;

char a[maxn],b[maxn];
int dp[maxn][maxn],tr[maxn][maxn];

void f(int B[][maxn],int i,int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (B[i][j] == 2) {
        f(B, i - 1, j-1);
        printf("%c ", a[i]);
    }
    else if (B[i][j] == 1) {
        f(B, i - 1, j);
    }
    else {
        f(B, i, j-1);
    }
}

int main(){
    int m,n;
    printf("please m,n:");
    scanf("%d %d",&m,&n);
    printf("X:");
    for (int i = 1; i <= m; ++i){
        scanf(" %c", &a[i]);
    }
    printf("Y:");
    for (int i = 1; i <= n; ++i){
        scanf(" %c", &b[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1 ; i <= m ; ++i){
        for (int j = 1 ; j <= n ; ++j){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                tr[i][j]=2;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    tr[i][j]=1;
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    tr[i][j]=0;
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    printf("%d\n",dp[m][n]);
    f(tr, m, n);
    system("pause");
    return 0;
}

//
//  main.cpp
//  Suanfa_7
//
//  Created by 姜姜 on 2021/6/23.
//


#include <stdio.h>
#define m 5   //投资的钱(万)
#define n 4   //投资的项目数
using namespace std;
int main() {
    int    f[100][100],max[100][100] = { 0 },p[100][100];//投资和收益，最大收益，方案
    for (int i = 0; i <= m; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &f[j][i]);
        }
    }
    //0 0 0 0
    //11 0 2 20
    //12 5 10 21
    //13 10 30 22
    //14 15 32 23
    //15 20 40 24
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            for (int k = 0; k <= j; k++){
                if (max[i][j] <= max[i - 1][j - k] + f[i][k]) {
                    max[i][j] = max[i - 1][j - k] + f[i][k];
                    p[i][j] = k;
                }
            }
        }
    }
    printf("最大收益：%d\n分配方案如下：\n",max[n][m]);
    int t = m;
    for (int i = n; i >= 1;i--) {
        printf("分配给第%d个项目%d万\n",i,p[i][t]);
        t -= p[i][t];
    }
}

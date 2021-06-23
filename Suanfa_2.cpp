//
//  main.cpp
//  Suanfa2
//
//  Created by 姜姜 on 2021/6/21.
//

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
#define speed() {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

const int maxn=1e4+100;
const int inf=0x3f3f3f3f;

int dis[maxn][maxn];
int n,m,u,v,w,vis[maxn],len[maxn],pre[maxn];
char res[maxn];

void Floyd(int n) {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);//floyd算法遍历
            }
        }
    }
    cout<<"距离矩阵"<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Dijkstra(int u) {
    memset(vis,0,sizeof vis);
    memset(len,inf,sizeof len);
    vis[u]=1;//标记起点
    for(int i=1; i<=n; i++)len[i]=dis[u][i];
//    for(int i=1;i<=n;i++)cout<<len[i]<<endl;
    int flag=1;
    int first=1;//第二个点的前置
    while(flag==1) {
        flag=0;
        int maxlen=inf,maxi=0;
        for(int i=1; i<=n; i++) {
            if(len[i]!=inf&&len[i]<maxlen&&vis[i]!=1) {
                maxlen=len[i];
                maxi=i;
                flag=1;
            }
        }//找到最近距离的点
        if(flag==0)break;
        vis[maxi]=1;
        if(first==1) {
            first=0;
            pre[maxi]=u;
        }
        for(int i=1; i<=n; i++) {
//                cout<<i<<" "<<len[i]<<" "<<len[maxi]+dis[maxi][i]<<endl;
            if(len[i]>len[maxi]+dis[maxi][i]) {
                pre[i]=maxi;
                len[i]=len[maxi]+dis[maxi][i];
            }//路径压缩
        }
    }
    int rescnt=1;
    cout<<"最短距离："<<len[n]<<endl;
    int now=n;
    while(now!=1) {
        res[rescnt++]=(char)(now+'a'-1);
        now=pre[now];
    }
    res[rescnt]='a';
    for(int i=rescnt;i>=1;i--){
        if(i!=rescnt)cout<<"->";
        cout<<res[i];
    }
    cout<<endl;
}

int main() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j)dis[i][j]=0;
            else dis[i][j]=inf;
        }
    }
    for(int i=1; i<=m; i++) {
        cin>>u>>v>>w;
        dis[u][v]=w;
    }

    cout<<"Floyd算法"<<endl;
    Floyd(n);
    cout<<"Dijkstra算法"<<endl;
    Dijkstra(1);

    return 0;
}

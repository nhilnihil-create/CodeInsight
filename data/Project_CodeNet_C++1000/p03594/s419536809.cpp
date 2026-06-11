#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;
#define LL long long
#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define lc (x<<1)
#define rc ((x<<1)|1)
const int N=505;
int n,m;
char c[N][N],g[]={'R','Y','G','B'};
void wk(int x,int y,int col){
    if (x>=1&&x<=n&&y>=1&&y<=m) c[x][y]=g[col];
}
void paint(int x,int y,int k,int col){
    for (int i=0;i<k;i++)
     for (int j=0;i+j<k;j++){
        if ((k&1)^((i+j)&1)){
            wk(x-i,y-j,col);wk(x-i,y+j,col);
            wk(x+i,y-j,col);wk(x+i,y+j,col);
        }
     }
}
int main(){
     //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    int i,j,k;
    scanf("%d%d%d",&n,&m,&k);
    if (k%2){
        for (i=1;i<=n;i++)
         for (j=1;j<=m;j++)
          if ((i+j)%2) c[i][j]='Y'; else c[i][j]='B';
    } else{
        int k2=k,f,g;k/=2;
        for (i=1,f=0;i-k+1<=n;i+=k2,f^=1){
            for (j=1,g=0;j-k+1<=m;j+=k2,g^=1) paint(i,j,k,f^g);
        }
        for (i=k+1,f=2;i-k+1<=n;i+=k2,f^=1){
            for (j=1+k,g=0;j-k+1<=m;j+=k2,g^=1) paint(i,j,k,f^g);
        }

        for (i=1,f=0;i-k+1<=n;i+=k2,f^=1){
            for (j=2,g=0;j-k+1<=m;j+=k2,g^=1) paint(i,j,k,f^g);
        }
        for (i=k+1,f=2;i-k+1<=n;i+=k2,f^=1){
            for (j=2-k,g=0;j-k+1<=m;j+=k2,g^=1) paint(i,j,k,f^g);
        }
    }
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++) putchar(c[i][j]);
        puts("");
    }

    return 0;
}

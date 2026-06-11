#pragma G++ optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define REG register
#define REP(i,x,y) for(REG int i=x;i<=y;i++)
#define UP(i,x,y) for(REG int i=x;i>=y;i--)
#define IN inline
#define ll long long 
#define inf 0x3f3f3f3f

const int maxn=200010;
int f[maxn],pos[maxn][30],n;
char s[maxn];
int main(){
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<26;i++)pos[n][i]=n;
    f[n]=1;f[n+1]=0;//即使没有后缀仍然需要长度为1，f[n]=1；如果没有相同字符的话就f[n+1]+1，所以f[n+1]=0。 
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++)pos[i][j]=pos[i+1][j];
        pos[i][s[i]-'a']=i;
        f[i]=n+1;
        for(int j=0;j<26;j++)f[i]=min(f[i],f[pos[i][j]+1]+1);
    }
    int T=f[0],p=0;
    while(T--){
        for(int j=0;j<26;j++)if(f[pos[p][j]+1]+1==f[p]){
            putchar('a'+j);
            p=pos[p][j]+1;
            break;
        }
    }
    return 0;
}
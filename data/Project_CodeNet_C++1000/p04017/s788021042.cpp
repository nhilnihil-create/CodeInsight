#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iostream>
typedef long long ll;
using namespace std;
const int maxn=101000;
int dis[maxn][35];
int n,l,q;
int num[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    scanf("%d%d",&l,&q);
    for(int i=1;i<=n;i++){
        int idx=(int)(upper_bound(num+1,num+n+1,num[i]+l)-num);
        idx--;
        dis[i][0]=idx;
    }
    for(int j=1;j<=30;j++){
        for(int i=1;i<=n;i++){
            dis[i][j]=dis[dis[i][j-1]][j-1];
        }
    }
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==b){
            printf("0\n");
            continue;
        }
        if(a>b) swap(a,b);
        int ans=0,cur=a;
        for(int i=30;i>=0;i--){
            if(dis[cur][i]<b){
                ans+=(1<<i);
                cur=dis[cur][i];
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
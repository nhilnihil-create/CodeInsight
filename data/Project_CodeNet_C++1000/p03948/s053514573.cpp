#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 1000000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;
int a[N];
int main() {
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
 
    int maxx=-INF,temp=-INF;
    for(int i=n;i>=1;i--){
        temp=max(temp,a[i]);//最大的价格
        maxx=max(maxx,temp-a[i]);//最大的贸易差
    }
    
    temp=-INF;
    int res=0;
    for(int i=n;i>=1;i--){
        temp=max(temp,a[i]);
        if(maxx==temp-a[i])
            res++;
    }
    printf("%d\n",res);
 
    return 0;
}
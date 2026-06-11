#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int cnt[100005];
    fill(cnt,cnt+100005,0);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        cnt[x]++;
        cnt[y]++;
    }
    for(int i = 1;i<=n;i++){
        if(cnt[i]&1){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
/*
1-n 0
2-n 1
3-n 2
-3 0
-2 1
-1 2
0 3
*/
/*
1 0
2 -10  01
3 -20 -1 1 0 2


*/
/*

k*cnt[i]-k*cnt[j]=i-j;
k*cnt[i]-i=k*cnt[j]-j
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5    3
1 2 3 5 6    4 
1 2 3 4 6
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/
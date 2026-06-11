#include<bits/stdc++.h>
using namespace std;
#define db double 
#define LL long long 
const int N = 1e5 + 11;
db x[N];
int m, a[N], n;
int stk[N], tp, to[N], res[N];
bool mark[N];
LL K;
int main(){
    cin>>n;
    for(int i = 1;i <= n; i++){
        scanf("%lf", &x[i]);
    }
    for(int i = n;i >= 1; i--)x[i] -= x[i-1], to[i] = i;
    cin>>m>>K;
    for(int i = 1;i <= m; i++){
        scanf("%d", &a[i]);
        swap(to[a[i]], to[a[i]+1]);
    }
    for(int i = 1;i <= n; i++){
        if(mark[i])continue;
        mark[i] = tp = 1; stk[1] = i; 
        int now = to[i];
        while(now != i)mark[now] = 1, stk[++tp] = now, now = to[now];
        for(int j = 1;j <= tp; j++)res[stk[j]] = stk[(j-1+K)%tp+1];
    }
    db t = 0;
    for(int i = 1;i <= n; i++){
        t += x[res[i]];
        printf("%.1lf\n", t);
    }
    return 0;
}

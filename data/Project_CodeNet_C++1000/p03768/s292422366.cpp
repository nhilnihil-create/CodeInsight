///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

const int maxn = 1000* 100+ 5;
int x[maxn], d[maxn], c[maxn], ans[maxn];
vector <int> aj[maxn];
set < pii > s;

void f(int v, int dis, int co){
    if(s.find({v, dis}) != s.end())
        return;
    s.insert({v, dis});
    if(dis == 0){
        if(ans[v] == 0)
            ans[v] = co;
    }
    else{
        f(v, dis - 1, co);
        for(int i = 0; i < SZ(aj[v]); i ++){
            int u = aj[v][i];
            f(u, dis - 1, co);
        }
    }
    return;
}

int32_t main(){
    int n, m;
    cin >>n >>m;
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >>u >>v;
        u --;
        v --;
        aj[u].pb(v);
        aj[v].pb(u);
    }
    int Q;
    cin >>Q;
    for(int i = 0; i < Q; i ++){
        cin >>x[i] >>d[i] >>c[i];
        x[i] --;
    }
    for(int i = Q - 1; i >= 0; i --){
        f(x[i], d[i], c[i]);
    }
    for(int i = 0; i < n; i ++)
        cout <<ans[i] <<' ';
    return false;
}


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

const int maxn = 1000* 100 + 5;
vector <int> aj[maxn];
bool mrk[maxn];
vector <int> v;
deque <int> q;

void dfs(int vv){
    mrk[vv] = true;
    v.pb(vv);
    for(int i = 0; i < SZ(aj[vv]); i ++){
        int u = aj[vv][i];
        if(!mrk[u]){
            dfs(u);
            return;
        }
    }
    return;
}

int32_t main(){
    int n, m, a, b;
    cin >>n >>m;
    for(int i = 0 ; i < m; i ++){
        int u, v;
        cin >>u >>v;
        u --;
        v --;
        aj[u].pb(v);
        aj[v].pb(u);
        a = u;
        b = v;
    }
    mrk[a] = true;
    mrk[b] = true;
    dfs(a);
    for(int i = 0; i < SZ(v); i ++)
        q.pf(v[i]);
    v.clear();
    dfs(b);
    for(int i = 0; i < SZ(v); i ++)
        q.pb(v[i]);
    cout <<SZ(q) <<endl;
    for(int i = 0; i < SZ(q); i ++)
        cout <<q[i] + 1 <<' ';
}

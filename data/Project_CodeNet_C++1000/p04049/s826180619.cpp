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
#define pipii pair< int, pair<int, int> >
#define plpll pair< ll, pair<ll, ll> >

const int maxn = 2005;
vector <int> aj[maxn];
int h[maxn];

void clr(){
    for(int i = 0; i < maxn; i ++)
        h[i] = -1;
}

void dfs(int v){
    for(int i = 0; i < SZ(aj[v]); i ++){
        int u = aj[v][i];
        if(h[u] == -1){
            h[u] = h[v] + 1;
            dfs(u);
        }
    }
    return;
}

int32_t main(){
    int n, k, ans = 2005;
    cin >>n >>k;
    for(int i = 0; i < n - 1; i ++){
        int u, v;
        cin >>u >>v;
        u --;
        v --;
        aj[u].pb(v);
        aj[v].pb(u);
    }
    if(k & 1){
        for(int v = 0; v < n; v ++){
            for(int j = 0; j < SZ(aj[v]); j ++){
                clr();
                int u = aj[v][j];
                h[u] = 0;
                h[v] = 0;
                dfs(u);
                dfs(v);
                int cn = 0;
                for(int i = 0; i < n; i ++){
                    if(h[i] > k/ 2)
                        cn ++;
                }
                xmin(ans, cn);
            }
        }
    }
    else{
        for(int i = 0; i < n; i ++){
            clr();
            h[i] = 0;
            dfs(i);
            int cn = 0;
            for(int j = 0; j < n; j ++){
                if(h[j] > k/ 2)
                    cn ++;
            }
            xmin(ans, cn);
        }
    }
    cout <<ans <<endl;
    return false;
}

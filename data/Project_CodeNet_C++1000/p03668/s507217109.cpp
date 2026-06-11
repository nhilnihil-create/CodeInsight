 #define PROB Treestrat

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define rep(i, l, r) for (int i = l; i<r;i++)
#define all(b) b.begin() , b.end()
#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define vi vector<int>
#define vd vector<double>
#define vs vector<string>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define turnOff(k, i) (k&(~(1<<(i-1))))
#define isOn(k, i) (k&&(1<<i-1)?true:false)
#define pll pair<long long int , long long int>
#define ull unsigned long long int
#define ll  long long int
#ifdef  DEBUG
#define MAXN 20
#else
#define MAXN 200050
#endif
#define MAXLG 20
#define endl '\n'
#define PI 3.14159265i3589793238
#define MOD (1000000007l)
#define INF (1000000007)
#define EPS (0.00000001)
#define treap treapNode*

vi adj[MAXN];


int dfs (int curr,int par = -1) {
    int nim = 0;
    for (int nxt : adj[curr]) {
        if (nxt!=par) {
            nim = nim ^(dfs(nxt,curr)+1);
        }
    }
    return nim;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    int n;
    cin>>n;
    rep (i,0,n-1) {
        int x,y;
        cin>>x>>y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    if(dfs(0)!=0) cout<<"Alice";
    else cout<<"Bob";
    return 0;
}














































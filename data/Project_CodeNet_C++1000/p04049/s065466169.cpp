#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int INF = 1e8;
const int MAXN = 3e5 + 200;
const  long double eps = 1e-9;
const long double pi = acos(-1.0);
using namespace std;

int n, k;
vector <int> g[MAXN];
int d[3001][3001];
void dis(){

}
void dis(int x){
    for (int i = 1; i <= n; i++) d[x][i] = -1;
    d[x][x] = 0;
    deque <int> q;
    q.pb(x);

    while (!q.empty()){
        int v = q.front();
        q.pop_front();
        for (auto u : g[v]){
            if (d[x][u] != -1) continue;
            d[x][u] = d[x][v] + 1;
            q.pb(u);
        }
    }

}
void solve(){
    cin >> n >> k;

    for (int i = 1; i <= n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y); g[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        dis(i);


    int ans = n;


    for (int v = 1; v <= n; v++){
        int kol = 0;
        if (k % 2 == 0) {
            for (int i = 1; i <= n; i++) if (d[v][i] > k / 2) kol++;
            ans = min(ans, kol);
        }else {
            for (auto u : g[v]){
                kol = 0;
                for (int i = 1; i <= n; i++) if (min(d[v][i], d[u][i]) > k / 2) kol++;
                ans = min(ans, kol);
            }
        }
    }

    cout << ans << endl;
}
/*
 6 1
 1 2
 2 3
 3 4
 4 5
 5 6
 */
int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(7);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout)
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++)
        solve();

}
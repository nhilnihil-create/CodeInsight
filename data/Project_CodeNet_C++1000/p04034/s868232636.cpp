#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
#define ll long long
const int inf = 1e8;
const ll INF = 1e18;
const int MAXN = 3e5 + 200;
const  long double eps = 1e-9;
const long double pi = acos(-1.0);
using namespace std;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1 -1};

int n, m;
bool can[MAXN];
int kol[MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        kol[i] = 1;
    can[1] = true;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        kol[x]--;
        kol[y]++;
        if (can[x])
            can[y] = true;
        if (can[x] && kol[x] == 0){
            can[x] =false;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (can[i]) ans++;
        cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(40);
    //freopen("inevit.in", "r", stdin);
    //freopen("inevit.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++)
        solve();


}
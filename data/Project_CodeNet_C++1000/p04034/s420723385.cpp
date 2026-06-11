#include <bits/stdc++.h>                        
#define pb push_back                            
#define mp make_pair                            
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define jonathan ios_base::sync_with_stdio(0)
#define livingston cin.tie(0)
using namespace std;                            
                                                
void yes() {cout << "YES" << endl;}                                               
void no() {cout << "NO" << endl;}                                                        
                                                
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};         
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1}; 

const int INF = 1e9 + 9;
const long long LINF = 1e18 + 8;
const double EPS = 1e-9;
const long long MOD = 1e9 + 7; //998244353
const double PI = acos(-1);

void solve() {
    int n, m; cin >> n >> m;
    vector<int> used(n + 1, false);
    vector<int> cnt(n + 1, 1);
    used[1] = true;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        used[y] = used[y] | used[x];
        cnt[x]--;
        cnt[y]++;
        if (cnt[x] == 0) used[x] = false;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += used[i];
    }
    cout << res << endl;
} 

int main() {
    jonathan; 
    livingston;
    solve();
    return 0;
}
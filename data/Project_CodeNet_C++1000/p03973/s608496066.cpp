#include <bits/stdc++.h>                        
#define pb push_back                            
#define mp make_pair                            
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define jonathan ios_base::sync_with_stdio(0)
#define livingston cin.tie(0)
using namespace std;                            
                                                
void yes() {cout << "Yes" << endl;}                                               
void no() {cout << "No" << endl;}                                                        
                                                
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};         
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1}; 

const int INF = 1e9 + 9;
const long long LINF = 1e18 + 8;
const double EPS = 1e-9;
const long long MOD = 1e9 + 7; //998244353
const double PI = acos(-1);

void solve() {
    int n; cin >> n;
    long long res = 0;
    long long last = 0;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        x--;
        long long d = x / (last + 1);
        res += d;
        if (d > 0) last = max(last, 1ll);
        else last = max(last, x + 1);
    }
    cout << res << endl;
}   

int main() {
    jonathan; 
    livingston;
    solve();
    return 0;
}
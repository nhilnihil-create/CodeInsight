#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, x;
    cin >> N >> x;
    if(x == 1 || x == 2*N-1){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
        vector<int> vec;
        rep2(i, 1, x-2) vec.pb(i);
        rep2(i, x+2, 2*N-1) vec.pb(i);
        rep(i, N-2) cout << vec[i] << endl;
        rep2(i, -1, 1) cout << x+i << endl;
        rep(i, N-2) cout << vec[N-2+i] << endl;
    }
}
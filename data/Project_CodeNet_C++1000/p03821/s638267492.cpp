#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll count = 0;
    for(ll i = n - 1; i >= 0; i--){
        if((a[i] + count) % b[i] != 0){
            count += b[i] - ((a[i] + count) % b[i]);
        }
    }
    cout << count << endl;
}
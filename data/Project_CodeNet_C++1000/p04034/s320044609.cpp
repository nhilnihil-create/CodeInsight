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
    ll n, m; cin >> n >> m;
    vector<ll> a(100100);
    rep(i, n) a[i] = 1;
    vector<bool> flag(100100, false);
    flag[0] = true;
    vector<ll> x(100100);
    vector<ll> y(100100);
    rep(i, m){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    rep(i, m){
        a[x[i]]--;
        a[y[i]]++;
        if(flag[x[i]]){
            flag[y[i]] = true;
            if(a[x[i]] == 0)flag[x[i]] = false;
        }
    }
    ll count = 0;
    rep(i, n) if(flag[i])count++;
    cout << count << endl;
}
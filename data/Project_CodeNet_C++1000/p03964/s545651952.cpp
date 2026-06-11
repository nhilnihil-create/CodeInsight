#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    ll a = 1, b = 1;
    rep(i,n){
        int x, y; cin >> x >> y;
        ll n = max((a + x - 1) / x, (b + y - 1)/ y);
        a = x * n, b = y * n;
    }
    cout << a + b << endl;
}
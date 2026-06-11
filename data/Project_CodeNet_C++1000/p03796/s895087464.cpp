#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

int main(){
    int n; cin >> n;
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
        ans %= mod; 
    }
    cout << ans << endl;
}
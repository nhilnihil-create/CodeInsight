#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97

int main() {
    ll n,k;cin >> n >> k;
    ll ans=k;
    for(int i = 0; i < n-1; i++) {
        ans *= k-1;
    }
    cout << ans << endl;

    return 0;
}
// Scc Puzzle
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    ll ans=0;
    ll x=max((ll)0, m-n*2);
    ans+=min(m/2, n);

    ans+=x/4;
    cout << ans << endl;
    return 0;
}
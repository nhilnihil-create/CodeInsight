#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> v(3*N);
    for(int i=0;i<3*N;i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<ll>());
    ll sum=0;
    for(int i=0,j=1;i<N;i++,j+=2) sum+=v[j];
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
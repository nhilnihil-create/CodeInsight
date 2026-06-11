#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    int n, k, x, y; cin>>n>>k>>x>>y;
    int ans = x*min(k, n);
    n -= min(k, n);
    ans += n*y;
    cout<<ans<<'\n';
    return 0;
}
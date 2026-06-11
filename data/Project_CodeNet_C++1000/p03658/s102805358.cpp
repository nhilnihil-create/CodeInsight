#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int k,n;
    cin >> n >> k;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(all(l),greater<>());
    ll sum=0;
    rep(i,k) sum+=l[i];

    cout << sum << endl;

    
    return 0;
}
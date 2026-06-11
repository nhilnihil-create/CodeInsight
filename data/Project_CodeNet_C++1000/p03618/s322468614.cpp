#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string A;
    cin >> A;
    map<char,ll> mp;
    rep(i,A.size()){
        mp[A[i]]++;
    }
    ll ans = A.size()*(A.size()-1)/2 + 1;
    for(char c='a';c<='z';c++){
        ans -= mp[c]*(mp[c]-1)/2;
    }
    cout << ans << endl;
    return 0;
}
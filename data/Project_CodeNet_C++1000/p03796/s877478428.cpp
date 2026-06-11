#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long N; cin>>N;
    ll power = 1;
    rep(i, N){
        power *= i+1;
        power %= 1000000007;
    }

    cout << power << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t

int main(){
    string S;
    cin >> S;
    ll N = S.size();
    map<char, ll> M;
    ll ans = (N*(N-1))/2;
    for(auto c : S) M[c]++;
    for(auto m : M){
        ll n = m.second;
        ans -= (n*(n-1))/2;
    }
    cout << ans+1 << endl;

}
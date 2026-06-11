#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll K,S;
    cin >> K >> S;

    ll count = 0;
    rep(i,K+1){
        rep(j,K+1){
            ll z = S - i - j;
            if(0 <= z && z <= K) count++;
        }
    }

    cout << count << endl;
}
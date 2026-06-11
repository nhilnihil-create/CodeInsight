#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    map<ll,ll> mp;
    rep(i,N){
        mp[A[i]]++;
    }
    ll ans = 0;
    for (map<ll,ll>::iterator itr = mp.begin(); itr != mp.end(); itr++){
        ans += (itr->second - 1);
    }
    ll count = (ans + 1) / 2;
    cout << N - count * 2 << endl;
}

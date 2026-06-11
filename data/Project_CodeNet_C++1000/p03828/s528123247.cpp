#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> prime(0);
    prime.push_back(2);
    for (ll i = 3; i <= N; i++){
        ll len = prime.size();
        bool isPrime = true;
        rep(j,len){
            if (i % prime[j] == 0) isPrime = false;
        }
        if (isPrime){
            prime.push_back(i);
        }
    }
    ll len = prime.size();
    vector<pair<ll,ll> > prime_copy(len);
    for (ll i = 0; i < len; i++){
        prime_copy[i].first = prime[i];
        prime_copy[i].second = 0;
    }
    for (ll i = 0; i < len; i++){
        for (ll j = 1; j <= N; j++){
            ll copy_j = j;
            while(true){
                if (copy_j % prime_copy[i].first != 0){
                    break;
                }
                else{
                    copy_j /= prime_copy[i].first;
                    prime_copy[i].second++;
                }
            }
        }
    }
    ll ans = 1;
    for (ll i = 0; i < len; i++){
        ans = (ans * (prime_copy[i].second + 1)) % 1000000007;
    }
    if (N == 1) cout << 1 << endl;
    else if (N == 2) cout << 2 << endl;
    else cout << ans << endl;
}

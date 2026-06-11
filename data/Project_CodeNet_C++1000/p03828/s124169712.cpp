#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

const ll mod = 1e9 + 7;

int main(void){
    ll n;
    cin >> n;

    vector<bool> isP(n+1);
    vector<ll> num(n+1);
    for(int i=0; i<=n; i++){
        isP[i] = true;
        num[i] = i;
    }
    isP[0] = false;
    isP[1] = false;

    vector<ll> prime;
    ll cnt = 0;
    for(int i=2; i<=n; i++){
        if(isP[i]){
            prime.push_back(i);
            cnt++;
            for(int j=2*i; j<=n; j+=i){
                isP[j] = false;
            }
        }
    }

    ll ans = 1;
    for(int i=0; i<cnt; i++){
        ll prm = prime[i];
        ll joo = 0;
        for(int j=2; j<=n; j++){
            if(num[j] % prm == 0){
                while(num[j] % prm == 0){
                    num[j] /= prm;
                    joo++;
                }
            }
        }
        joo %= mod;
        ans *= (joo+1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
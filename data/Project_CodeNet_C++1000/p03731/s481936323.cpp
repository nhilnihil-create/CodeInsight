#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,T;
    cin >> N >> T;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    ll ans = 0;
    rep(i,N - 1){
        if (vec[i + 1] - vec[i] < T){
            ans += (vec[i + 1] - vec[i]);
        }
        else{
            ans += T;
        }
    }
    ans += T;
    cout << ans << endl;
}

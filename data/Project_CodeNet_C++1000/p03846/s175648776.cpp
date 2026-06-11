#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    sort(all(vec));
    bool possible = true;
    if (N % 2 == 0){
        rep(i,N){
            if (i % 2 == 0){
                if (vec[i] != i + 1) possible = false;
            }
            else{
                if (vec[i] != i) possible = false;
            }
        }
    }
    else{
        rep(i,N){
            if (i % 2 == 0){
                if (vec[i] != i) possible = false;
            }
            else{
                if (vec[i] != i + 1) possible = false;
            }
        }
    }
    if (!possible) cout << 0 << endl;
    else{
        ll ans = 1;
        ll num = N / 2;
        rep(i,num){
            ans = (ans * 2) % 1000000007;
        }
        cout << ans << endl;
    }
}

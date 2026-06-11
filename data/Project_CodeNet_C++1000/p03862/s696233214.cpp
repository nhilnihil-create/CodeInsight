#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,x;
    cin >> N >> x;
    vector<ll> box(N);
    rep(i,N){
        cin >> box[i];
    }
    ll ans = 0;
    if (box[0] + box[1] > x){
        if (box[0] > x){
            ans += (box[0] + box[1] - x);
            box[1] = 0;
        }
        else{
            ans += (box[0] + box[1] - x);
            box[1] -= (box[0] + box[1] - x);
        }
    }
    for (ll i = 1; i < N - 1; i++){
        if (box[i] + box[i + 1] > x){
            ans += (box[i] + box[i + 1] - x);
            box[i + 1] -= (box[i] + box[i + 1] - x);
        }
    }
    cout << ans << endl;
}


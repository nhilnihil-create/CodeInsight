#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll n; cin >> n;
    ll T; cin >> T;
    vector<ll> t(n);
    rep(i, n) cin >> t.at(i);

    ll now = t.at(0);
    ll last = t.at(0);
    ll cnt = 0;
    for(int i=0; i<n; i++){
        if(i==n-1){
            cnt+=T;
            break;
        }
        if(t.at(i)+T>=t.at(i+1)){
            cnt += t.at(i+1) - t.at(i);
        }
        else{
            cnt += T;
        }
    }

    cout << cnt << endl;
    return 0;
}

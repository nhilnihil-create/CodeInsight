#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    if(n%2==0){
        rep(i, n){
            if(a.at(i)%2==0){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    else{
        int cnt = 0;
        rep(i, n){
            if(a.at(i)%2!=0){
                cout << 0 << endl;
                return 0;
            }
            if(a.at(i)==0){
                cnt++;
            }
            if(cnt==2){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    ll sum = 1;
    ll mod = 1e9 + 7;
    rep(i, n/2){
        sum *= 2LL;
        sum %= mod;
    }
    cout << sum % mod << endl;
    return 0;
}

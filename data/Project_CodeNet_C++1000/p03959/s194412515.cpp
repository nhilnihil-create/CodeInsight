#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

int main(){
    int N; cin >> N;
    vector<ll> t(N+2, 0), a(N+2, 0);
    for(int i=1; i<=N; i++) cin >> t[i];
    for(int i=1; i<=N; i++) cin >> a[i];

    ll ans = 1LL;
    for(int i=1; i<=N; i++){
        if(t[i-1] == t[i]){
            if(a[i] == a[i+1]){
                ans = ans*min(t[i], a[i])%mod;
            }
            else{
                if(a[i] > t[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        else{
            if(a[i] == a[i+1]){
                if(t[i] > a[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }
            else{
                if(t[i] != a[i]){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    cout << ans << endl;
    
}
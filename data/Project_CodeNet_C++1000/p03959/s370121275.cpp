#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll T[n], A[n];
    for(int i=0;i<n;i++) cin >> T[i];
    for(int i=0;i<n;i++) cin >> A[i];
    // max value of candidates, flag if only one or not
    vector<pair<ll, bool> > vp;
    for(int i=0;i<n;i++){
        if(i == 0 || T[i] > T[i-1]){
            vp.push_back(make_pair(T[i], true));
        }else if(T[i] == T[i-1]){
            vp.push_back(make_pair(T[i], false));
        }else{
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i=n-1;i>=0;i--){
        if(i == n-1 || A[i] > A[i+1]){
            if(vp[i].second && vp[i].first == A[i]){
                ans *= 1LL;
            }else if(!(vp[i].second) && vp[i].first >= A[i]){
                ans *= 1LL;
            }else{
                cout << 0 << endl;
                return 0;
            }
        }else if(A[i] == A[i+1]){
            if(vp[i].second && vp[i].first <= A[i]){
                ans *= 1LL;
            }else if(!(vp[i].second)){
                ans *= min(vp[i].first, A[i]);
                ans %= MOD;
            }else{
                cout << 0 << endl;
                return 0;
            }
        }else{
            cout << 0 << endl;
            return 0;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}
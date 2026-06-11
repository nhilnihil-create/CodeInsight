#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0, ct=0;
vector<ll> A, S;

signed main(){
    cin >> N;
    if(N==1) {
        cout << "YES" << endl;
        return 0;
    }
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
        tmp += a;
    }
    ct = N*(N+1)/2;
    if(tmp%ct==0) ct = tmp/ct;
    else {
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0;i<N-1;i++) {
        S.push_back(ct-(A[i+1]-A[i]));
    }
    S.push_back(ct-(A[0]-A[N-1]));
    for(int i=0;i<N;i++) {
        //cout << S[i] << endl;
        if(S[i]%N!=0) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            if(S[i]<0||S[i]>ct*N) {
                cout << "NO" << endl;
                return 0;
            }
            ans += S[i]/N;
        }
    }
    if(ans==ct) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A, B;
map<ll,ll> M;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
        B.push_back(a);
    }
    sort(B.begin(), B.end());
    for(int i=0;i<N;i++) {
        M[B[i]] = i;
    }
    for(int i=0;i<N;i++) {
        if((i-M[A[i]])%2) {
            ans++;
            //cout << A[i] << " " << M[A[i]] << endl;
        }
    }
    cout << ans/2 << endl;
    return 0;
}
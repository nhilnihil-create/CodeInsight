#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, L, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N >> L;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<N-1;i++) {
        tmp = max(tmp, A[i]+A[i+1]);
    }
    if(tmp<L) {
        cout << "Impossible" << endl;
        return 0;
    }
    else {
        cout << "Possible" << endl;
        for(int i=0;i<N-1;i++) {
            if(tmp==A[i]+A[i+1]) {
                ans = i+1;
            }
        }
        for(int i=0;i<N-1;i++) {
            if(i+1==ans) break;
            cout << i+1 << endl;
        }
        for(int i=0;i<N-1;i++) {
            if(N-1-i==ans) break;
            cout << N-1-i << endl;
        }
        cout << ans << endl;
        return 0;

    } 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)

typedef pair<int,int> P;
typedef long long ll;

const int INF = 1001001001;
const int mod = 1000000007;
const double PI=acos(-1);

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> S(N);
    rep(i,N) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    rep(i,N) {
        if (i==0) {
            S[i] = A[i];
        }
        else {
            S[i] = S[i-1] + A[i]; 
        }
    }

    ll ans = N;

    rep(i,N-1) {
        if (A[N-1-i]>S[N-2-i]*2) {
            ans = i+1;
            break;
        }
    }
    cout << ans << endl;
}

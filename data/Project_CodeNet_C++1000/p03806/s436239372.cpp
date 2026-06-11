#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, M1, M2, ans=0, tmp=0;
vector<ll> A, B, C;
vector<vector<ll>> DP;

signed main(){
    cin >> N >> M1 >> M2;
    DP.resize(N);
    for(int i=0;i<N;i++) {
        DP[i].resize(4000, INF);
    }
    for(int i=0;i<N;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        A.push_back(M2*a-M1*b);
        DP[i][2000+M2*a-M1*b] = c;
        C.push_back(c);
    }
    for(int i=1;i<N;i++) {
        for(int j=0;j<4000;j++) {
            DP[i][j] = min(DP[i][j], DP[i-1][j]);
            if(j-A[i]>=0) DP[i][j] = min(DP[i][j], DP[i-1][j-A[i]]+C[i]);
        }
    }
    if(DP[N-1][2000]>=INF) cout << -1 << endl;
    else cout << DP[N-1][2000] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,M,R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    rep(i,R) {
        int a;
        cin >> a;
        a--;
        r[i] = a;
    }
    sort(r.begin(),r.end());
    
    vector<vector<ll>> C(N,vector<ll> (N,INF));

    rep(i,M) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        C[a][b] = c;
        C[b][a] = c;
    }

    rep(k,N) {
        rep(i,N) {
            rep(j,N) {
                C[i][j] = min(C[i][j], C[i][k]+C[k][j]);
            }
        }
    }

    ll ans = INF;
    do {
        ll tmp = 0;
        rep(i,r.size()-1) {
            tmp += C[r[i]][r[i+1]];
        }
        ans = min(ans,tmp);
    } while (std::next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}

#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int N, A[100001];
ll dp[100001][3];
const ll MI = LONG_MIN / 3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    cin >> A[0];
    FOR(i, 1, N) {
        char c; cin >> c;
        cin >> A[i];
        if(c == '-')A[i] = -A[i];
    }

    rep(i, N + 1)rep(j, 3)dp[i][j] = MI;

    dp[0][0] = 0;
    rep(i, N) rep(j, 3) if(dp[i][j]>MI){
        for(int nj = 0; nj <= min(j + (A[i]<0), 2); ++nj) {
            smax(dp[i + 1][nj], dp[i][j] + ((j & 1) ? -A[i] : A[i]));
        }
    }

    cout << dp[N][0] << endl;
}
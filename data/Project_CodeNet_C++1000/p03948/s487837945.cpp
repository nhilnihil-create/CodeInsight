#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const llint INF = 9999999999999999;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;
    vector<llint> A(N);
    REP(i, N) cin >> A[i];
    llint maxv = -INF;
    llint minv = A[0];
    int ans = 1;
    FOR(i, 1, N){
        if(maxv < A[i]-minv){
            maxv = A[i]-minv;
            ans = 1;
        }
        else if(maxv == A[i]-minv) ans++;
        minv = min(minv, A[i]);
    }
    cout << ans << "\n";
    return 0;
}
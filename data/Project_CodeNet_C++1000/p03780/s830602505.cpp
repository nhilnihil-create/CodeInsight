#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(ll i=0; i<(ll)(n); i++)
#define FOR(i,n,m) for (ll i=n; i<(ll)(m); i++)
#define pb push_back
#define INF 1000000007LL
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)

typedef long long ll;
typedef pair<int,int> p;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

int N, K;
vector<int> a;

bool isUnnecessary(int cur) {
    // dp[x][y] = x枚目まで使った時総和をyにできるか？
    vector<vector<bool> > dp(N+1, vector<bool>(K+1, false));
    dp[0][0] = 1;
    REP(i, N) REP(j, K+1) {
        if (i == cur) {
            dp[i+1][j] = dp[i][j];
        } else {
            if(dp[i][j]) {
                if (j + a[i] <= K) {
                    dp[i+1][j+a[i]] = 1;
                }
                dp[i+1][j] = 1;
            }
        }
    }
    bool ret = false;
    FOR(i, max(0, K-a[cur]), K) {
        ret |= dp[N][i];
    }
    
    return !ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    a = vector<int>(N);
    REP(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    
    
    // コーナーケース (良い集合なし)
    {
        ll sum = 0;
        for(auto x: a) {
            sum += x;
        }
        if (sum < K) {
            cout << N << endl;
            return 0;
        }
    }
    
    int lb = 0, ub = N;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if (isUnnecessary(mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    
    if (!isUnnecessary(lb)) {
        cout << 0 << endl;
    } else {
        cout << lb + 1 << endl;
    }
    
    return 0;
}


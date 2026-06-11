#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, P> P3;
typedef pair<P, P> PP;
constexpr ll MOD = ll(1e9 + 7);
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-9;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i > 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int dp[MAX_N][21]; // dp[i][j] 頂点iから2^j回移動して到達できる最大頂点

int main() {
    int N, L, Q;
    cin >> N;
    vector<int> x(N);
    for(int i=0;i<N;i++){
        cin >> x[i];
    }
    cin >> L;
    for(int i=0;i<N-1;i++){
        dp[i][0] = upper_bound(x.begin(), x.end(), x[i]+L) - x.begin() - 1;
    }
    dp[N-1][0] = N;
    dp[N][0] = N;
    // doubling
    for(int j=0;j<20;j++){
        for(int i=0;i<=N;i++){
            dp[i][j+1] = dp[dp[i][j]][j];
        }
    }

    cin >> Q;
    for(int i=0;i<Q;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a, b);
        int now = a, cnt = 0;
        while(now != b){
            for(int j=20;j>=0;j--){
                if(dp[now][j] <= b){
                    now = dp[now][j];
                    cnt += 1<<j;
                    break;
                }
                else if(j==0){
                    now = b;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

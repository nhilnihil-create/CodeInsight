#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans = 0, N, C, K;
vll T;
vector<pii> vp;
int cnt, cur, tmp = 0, num, t, tprev;

void solve(){
    sort(T.begin(), T.end());

    ans++;
    cur = T[0];
    tmp = 1;

    for(int i = 1; i < N; ++i){
        if(tmp == C || T[i] - cur > K){
            ans++;
            tmp = 1;
            cur = T[i];
        } else tmp++;
    }

    cout << ans << endl;
}

int main(){
    cin >> N >> C >> K;

    T.resize(N);
    rep(i, N) {
        cin >> T[i];
    }

    solve();
}

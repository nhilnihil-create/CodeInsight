#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans = 0;
int N,X;
vi A;

void solve(){
    for(int i = 1; i < N; ++i){
        int diff = A[i] + A[i-1] - X;
        // cout << diff << endl;
        if(diff > 0){
            ans += diff;
            int tmp = diff - A[i];
            A[i] -= min(diff, A[i]);
            A[i-1] -= max(tmp, 0);
        }
    }

    cout << ans << endl;
}

int main(){
    cin >> N >> X;
    A.resize(N);

    rep(i, N) cin >> A[i];

    solve();
}

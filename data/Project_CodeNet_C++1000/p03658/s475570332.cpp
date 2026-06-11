#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    int N,K;
    cin >> N >> K;
    vector<int> V(N);
    rep(i,N) {
        cin >> V[i];
    }
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    int ans = 0;
    rep(i,K) {
        ans += V[i];
    }
    cout << ans << endl;
}


#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, M, ans=0, tmp=0;
vector<vector<ll>> d;
vector<ll> A, B, C;

void warshall_floyd() { // nは頂点数
  for (int i = 0; i < N; i++)      // 経由する頂点
    for (int j = 0; j < N; j++)    // 開始頂点
      for (int k = 0; k < N; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

signed main(){
    cin >> N >> M;
    d.resize(N);
    for(int i=0;i<N;i++) {
        d[i].resize(N, INF);
        d[i][i] = 0;
    }
    for(int i=0;i<M;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
        d[b][a] = c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
    }
    warshall_floyd();
    for(int i=0;i<M;i++) {
        if(d[A[i]][B[i]]!=C[i]||d[B[i]][A[i]]!=C[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, M, R, ans=0, tmp=0;
vector<ll> Rs;
vector<vector<ll>> D;

signed main(){
    cin >> N >> M >> R;
    Rs.resize(R);
    D.resize(N);
    for(int i=0;i<N;i++) {
        D[i].resize(N, INF);
        D[i][i] = 0;
    }
    for(int i=0;i<R;i++) {
        cin >> Rs[i];
        Rs[i]--;
    }
    //cout << "OK" << endl;
    for(int i=0;i<M;i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        D[a][b] = c;
        D[b][a] = c;
    }
    //cout << "OK" << endl;
    for(int k=0;k<N;k++) {
        for(int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
                D[j][i] = D[i][j];
            }
        }
    }
    //cout << "OK" << endl;
    vector<int> v;
    for(int i=0;i<min(R,min(8LL, N));i++) {
        v.push_back(i);
    }
    ans = INF;
    do {
        tmp = 0;
        for(int i=0;i<min(R,min(8LL, N))-1;i++) {
            tmp += D[Rs[v[i]]][Rs[v[i+1]]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}
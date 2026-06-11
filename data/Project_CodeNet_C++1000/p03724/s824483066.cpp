#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> num(N);
    for (int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        num[a]++;
        num[b]++;
    }
    bool ok = true;
    for (int i=0;i<N;i++){
        if (num[i]%2==1) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    ll minf = -20000000000000;
    vector<vector<ll>> edge;
    for (int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }
    vector<ll> point(N+1, minf);
    point[1] = 0;
    for (int i = 0; i < N; i++) {
        for (auto p : edge) {
            point[p[1]] = max(point[p[0]] + p[2], point[p[1]]);
        }
    }
    ll ans1 = point[N];
    for (int i = 0; i < N; i++) {
        for (auto p : edge) {
            point[p[1]] = max(point[p[0]] + p[2], point[p[1]]);
        }
    }
    ll ans2 = point[N];
    if (ans1 == ans2) cout << ans1 << endl;
    else cout << "inf\n";
}

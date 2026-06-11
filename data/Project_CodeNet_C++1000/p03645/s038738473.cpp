#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A;

    map<int, int> mp;

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1 && b != N) mp[b]++;
        if(b == N && a != 1) mp[a]++;
    }
    string ans = "IMPOSSIBLE";
    for (auto p : mp) {
        if (p.second >= 2) ans = "POSSIBLE";
    }
    cout << ans << endl;
    return 0;
}
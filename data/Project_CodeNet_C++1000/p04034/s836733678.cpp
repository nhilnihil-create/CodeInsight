#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    int cnt[N], red[N] = {};
    for(int i = 0; i < N; i++) cnt[i] = 1;
    red[0] = 1;

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cnt[x]--;
        cnt[y]++;
        if(red[x] == 1) red[y] = 1;
        if(cnt[x] <= 0) red[x] = 0;
    }
    int tmp = 0;
    for(int i = 0; i < N; i++)
        if(red[i] == 1) tmp++;
    cout << tmp << "\n";
    return 0;
}
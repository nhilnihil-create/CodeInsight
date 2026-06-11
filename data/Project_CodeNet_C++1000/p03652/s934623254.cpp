#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
bool chmax(int &a, int b) { if (a < b) { a = b; return 1; } return 0; }
void chmin(int &a, int b) { if (a > b) { a = b; } }
const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    queue<int> data[N];
    vector<int> user(M, 0);
    vector<bool> is_open(M, true);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a; cin >> a; a--;
            data[i].emplace(a);
        }
    }
    
    auto now_max = [&]()->pair<int, int> {
        // return { amount, index }
        int p = 0, idx = -1;
        for (int i = 0; i < M; i++) {
            if (chmax(p, user[i])) idx = i;
        }
        return make_pair(p, idx);
    };
    
    auto count_participant = [&]() {
        fill(user.begin(), user.end(), 0);
        for (int i = 0; i < N; i++) user[data[i].front()]++;
    };
    
    count_participant();
    int ans = now_max().first;
    for (int _ = 0; _ < M-1; _++) {
        count_participant();
        int mx, id; tie(mx, id) = now_max();
        chmin(ans, mx);
        is_open[id] = false;
        for (int i = 0; i < N; i++) {
            while (!is_open[data[i].front()]) data[i].pop();
        }
    }
    
    cout << ans << endl;
    return 0;
}
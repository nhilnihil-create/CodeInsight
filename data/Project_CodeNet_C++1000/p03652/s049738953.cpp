#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> visit(m+1, false);
    vector<deque<int>> dq(n, deque<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m ;j++) {
            cin >> dq[i][j];
        }
    }
    int ans = n;
    for(int i = 0; i < m; i++) {
        unordered_map<int, int> cnt;
        int max_cnt = 0;
        int target = -1;
        for(int j = 0; j < n; j++) {
            if (++cnt[dq[j].front()] > max_cnt) {
                max_cnt = cnt[dq[j].front()];
                target = dq[j].front();
            }
        }
        ans = min(ans, max_cnt);
        visit[target] = true;
        for(int j = 0; j < n; j++) {
            while(!dq[j].empty() && visit[dq[j].front()] == true) {
                dq[j].pop_front();
            }
        }
    }
    cout << ans << endl;

    return 0;
}


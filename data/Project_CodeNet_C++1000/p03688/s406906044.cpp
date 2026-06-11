#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    int N;
    cin >> N;
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    string ans;
    if (mp.size() == 1) {
        int X = mp.begin()->first;
        if ((1 <= X && X <= N / 2) || X == N - 1)
            ans = "Yes";
        else
            ans = "No";
    }
    if (mp.size() > 2) ans = "No";
    if (mp.size() == 2) {
        pair<int, int> p1 = *mp.begin();
        pair<int, int> p2 = *(++mp.begin());
        if (p1.first < p2.first) swap(p1, p2);
        if (p1.first - p2.first > 1 || p1.second == 1)
            ans = "No";
        else {
            int m = p1.second / 2, x = p2.second, X = p1.first;
            ans = (x + 1 <= X && X <= x + m ? "Yes" : "No");
        }
    }
    cout << ans << endl;
    return 0;
}
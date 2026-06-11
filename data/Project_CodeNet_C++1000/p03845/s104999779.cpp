#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;

    int total = 0;
    vector<int> times;
    rep(_, n) {
        int time;
        cin >> time;
        times.push_back(time);
        total += time;
    }

    int m;
    cin >> m;

    while (m--) {
        int idx, stimulation;
        cin >> idx >> stimulation;
        cout << (total - times[idx - 1] + stimulation) << endl;
    }
}
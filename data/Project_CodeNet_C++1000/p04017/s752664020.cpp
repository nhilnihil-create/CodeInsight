#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> hotels(n);
    for (int i = 0; i < n; i++)cin >> hotels[i];

    int l;
    cin >> l;
    vector<vector<int>> move(n, vector<int>(25));
    for (int i = 0; i < n; i++) {
        move[i][0] = upper_bound(hotels.begin(), hotels.end(), hotels[i] + l) - hotels.begin() - 1;
    }
    for (int j = 1; j < 25; j++) {
        for (int i = 0; i < n; i++) {
            move[i][j] = move[move[i][j - 1]][j - 1];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        if (from > to)swap(from, to);

        int ok = 1000000;
        int ng = 0;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;

            int now = from;
            for (int j = 0; j < 25; j++) {
                if ((1 << j) & mid)now = move[now][j];
            }

            if (now >= to)ok = mid;
            else ng = mid;
        }

        cout << ok << endl;
    }
    return 0;
}

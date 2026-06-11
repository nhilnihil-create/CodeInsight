#include <bits/stdc++.h>
using namespace std;

int main() {
        int N;
        int cnt[105] = {};
        int maxv = 0;
        bool flag = true;

        cin >> N;
        for (int i = 0; i < N; i++) {
                int a;
                cin >> a;
                cnt[a]++;
                maxv = max(maxv, a);
        }
        
        int m = (maxv + 1) / 2;
        if (cnt[m] != 1 + (maxv & 1)) flag = false;

        cnt[m] = 0;
        for (int i = m + 1; i <= maxv; i++) {
                if (cnt[i] < 2) flag = false;
                cnt[i] = 0;
        }
        
        if (!flag || accumulate(cnt, cnt + 105, 0) > 0) {
                cout << "Impossible" << endl;
        } else {
                cout << "Possible" << endl;
        }

        return (0);
}

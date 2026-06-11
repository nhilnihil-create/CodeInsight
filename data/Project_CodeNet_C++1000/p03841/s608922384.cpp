#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> x(n), ans(n * n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
        ans[--x[i]] = i + 1;
    }

    vector<int> cnt(n + 1), ok;
    for(int i = 0; i < n * n; ++i) {
        if(ans[i] != 0) {
            const int val = ans[i];
            if(cnt[val] != val - 1) {
                ans.clear();
                break;
            }
            cnt[val] = -1;
            for(int j = 0; j < n - val; ++j) {
                ok.push_back(val);
            }
        } else {
            int use = -1;
            auto calc = [&] (int val) {
                return x[val - 1] - i - (val - cnt[val]);
            };
            for(int j = 1; j <= n; ++j) {
                if(cnt[j] == -1 || cnt[j] + 1 == j) continue;
                if(use == -1 || calc(j) < calc(use)) {
                    use = j;
                }
            }
            if(use == -1) {
                if(ok.empty()) {
                    ans.clear();
                    break;
                }
                ans[i] = ok.back();
                ok.pop_back();
            } else {
                ans[i] = use;
                ++cnt[use];
            }
        }
    }

    if(ans.empty()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(int i = 0; i < n * n; ++i) {
            cout << ans[i] << " \n"[i + 1 == n * n];
        }
    }
}

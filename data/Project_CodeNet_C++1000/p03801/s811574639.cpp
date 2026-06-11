#include <bits/stdc++.h>
using namespace std;

#define ever ;true;
#define Dbug(x) cout << "Debug: " << #x << " = " << x << endl
#define _ << ", " << 
#define ll long long
#define int ll
#define all(v) v.begin(), v.end()

int n;

map<int, int> cnt, smallest_idx;
vector<int> freq;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n; freq.resize(n + 1);
    for (int i = 1, inp; i <= n; i++) {
        cin >> inp, cnt[inp]++;
        if (!smallest_idx.count(inp))
            smallest_idx[inp] = i;
    }

    for (auto it = cnt.rbegin(); it != cnt.rend(); it++) {
        auto nxt = it; nxt++;
        int val = (*it).first, times = (*it).second;
        int val_nxt = (*nxt).first;
        if (nxt == cnt.rend()) {
            freq[smallest_idx[val]] += times * (val - 0);
            continue;
        }
        freq[smallest_idx[val]] += times * (val - val_nxt);
        cnt[val_nxt] += times;
        smallest_idx[val_nxt] = min(smallest_idx[val], smallest_idx[val_nxt]);
    }

    for (int i = 1; i <= n; i++)
        cout << freq[i] << "\n";
    
}
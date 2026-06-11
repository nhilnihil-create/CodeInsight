#include <algorithm>
#include <stack>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n+1]; for (int i = 0; i < n; i++) cin >> a[i+1];
    a[0] = 0;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++) if (a[s.top()] < a[i]) s.push(i);
    map<int, int> mp;
    vector<long long> ans(n+1, 0);
    for (int i = 1; i <= n; i++) mp[a[i]]++;
    while (s.size() > 1) {
        int i = s.top();
        s.pop();
        int j = s.top();
        for (auto it = mp.upper_bound(a[j]); it != mp.end(); it = mp.erase(it)) {
            mp[a[j]] += it->second;
            ans[i] += (long long)(it->first - a[j]) * it->second;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}

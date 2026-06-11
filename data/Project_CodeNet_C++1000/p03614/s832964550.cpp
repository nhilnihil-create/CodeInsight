#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (p[i] == i + 1)
            v.push_back(i);
    int cnt = (v.size()? 1: 0), ans = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1] + 1)
            cnt++;
        else {
            ans += (cnt + 1) / 2;
            cnt = 1;
        }
    }
    if (cnt)
        ans += (cnt + 1) / 2;
    cout << ans << "\n";
    return 0;
}
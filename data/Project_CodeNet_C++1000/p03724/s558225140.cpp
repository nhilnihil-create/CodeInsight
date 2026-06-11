#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, m; cin >> n >> m;
    vector<int> cnt(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cnt[a - 1]++;
        cnt[b - 1]++;
        cnt[a - 1] %= 2;
        cnt[b - 1] %= 2;
    }
    cout << (count(cnt.begin(), cnt.end(), 1) ? "NO" : "YES") << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    int num = 0;
    rep(i, k) num += l[i];
    cout << num << endl;
    return 0;
}
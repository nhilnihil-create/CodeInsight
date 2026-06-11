#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());
    cout << ab[n - 1].first + ab[n - 1].second << endl; 
    return 0;
}
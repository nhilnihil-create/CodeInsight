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
    vector<int> a(n);
    int num = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if(a % 2 == 1) num++;
    }
    if(num % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//typedef int64_t int;
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precise cout.precision(10); cout << fixed;
#define pb push_back
#define mk make_pair
#define endl "\n"
#define int int64_t
#define ll long long
#define in(num,n) std::vector<int> num(n); for (int i = 0; i < n; i++)cin >> num[i]
const ll Inf = 1e9 + 7;
void solve() {
    string str;
    cin >> str;
    std::map<char, int> mp;
    bool eq = true;
    for (int i = 0; i < str.size(); i++)mp[str[i]]++;
    for (auto x : mp) {
        if (x.second % 2 != 0)eq = false;
    }
    if (eq)cout << "Yes" << endl;
    else cout << "No" << endl;
}


int32_t main()
{
    fastio;
    precise;

    //int test; cin >> test; while (test--)
    solve();
    return 0;
}
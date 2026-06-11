#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

string S;

bool dfs(string &a){
    if(S.size() == a.size() && S == a){
        return true;
    }

    if (S.size() < a.size()) return false;
    if (!equal(a.begin(), a.end(), S.begin())) return false;

    vector<string> z = {"dream", "dreamer", "erase", "eraser"};

    for(auto y : z){
        a += y;
        if (dfs(a)) {
            return true;
        }
        a.erase(a.size() - y.size());
    }
    return false;
}

int main() {
    cin >> S;

    string T;
    string ans = dfs(T) ? "YES" : "NO";

    cout << ans << endl;
}

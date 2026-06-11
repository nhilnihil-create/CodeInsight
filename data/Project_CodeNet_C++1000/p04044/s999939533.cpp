#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
#define coa cout << ans << endl; return 0;
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;


int main(){
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    sort(s.begin(), s.end());

    string ans = "";
    for(auto iter = s.begin(); iter != s.end(); iter++){
        ans += *iter;
    }

    coa;
}

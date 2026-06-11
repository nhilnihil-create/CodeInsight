#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

void str_replace(string &s, string target, string replacement) {
    if (!target.empty()) {
        string::size_type pos = 0;
        while ((pos = s.find(target, pos)) != string::npos) {
            s.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    while (t.find("()") != string::npos) {
        str_replace(t, "()", "");
    }
    string lef = "";
    string rig = "";
    rep(i,t.size()) {
        if (t[i] == ')') lef += '(';
        else rig += ')';
    }
    cout << lef + s + rig << endl;
}
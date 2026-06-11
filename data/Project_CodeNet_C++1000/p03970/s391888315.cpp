#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string t;
    t = "CODEFESTIVAL2016";
    int num = 0;
    rep(i, 16) {
        if(s[i] != t[i]) num++;
    }
    cout << num << endl;
    return 0;
}
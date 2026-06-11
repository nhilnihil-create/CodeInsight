#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxe = 0;
    int count = 0;
    rep(i, n) {
        if(s[i] == 'I') count++;
        else count--;
        maxe = max(maxe, count);
    }
    cout << maxe << endl;
    return 0;
}
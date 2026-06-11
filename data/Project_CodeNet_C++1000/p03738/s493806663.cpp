#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    if(a.size() > b.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    else if(a.size() < b.size()) {
        cout << "LESS" << endl;
        return 0;
    }
    else {
        rep(i, a.size()) {
            if(a[i] > b[i]) {
                cout << "GREATER" << endl;
                return 0;
            }
            else if(a[i] < b[i]) {
                cout << "LESS" << endl;
                return 0;
            }
        }
    }
    cout << "EQUAL" << endl;
    return 0;
}
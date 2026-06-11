#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

string str;

void recursive(ll num,ll &su, string op) {
    if (num == str.size() - 1) {
        vector<ll> OP;
        for (int i = 0; i < op.size(); i++) OP.push_back(op[i] - '0');
        vector<ll> vec;
        int j = 0;
        for (int i : OP) {
            vec.push_back(stoll(str.substr(j, i + 1 - j)));
            j = i + 1;
        }
        vec.push_back(stoll(str.substr(j, str.size() - j)));

        for (int i = 0; i < op.size() + 1; i++) su += vec[i];
        return;
    }

    recursive(num + 1, su, op + to_string(num));
    recursive(num + 1, su, op);
    return;
}

int main() {
    cin >> str;
    ll su = 0, num = 0;
    string op = "";
    recursive(0, su, "");
    cout << su << endl;
}
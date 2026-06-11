#include <bits/stdc++.h>
using namespace std;

long parse_eq(string x) {
    string char_stack = "";
    long res = 0;
    for (int i = 0; i < x.length(); ++i)
    {
        if (x[i] != '+') {
            char_stack += x[i];
        }
        else
        {
            res += stol(char_stack);
            char_stack = "";
        }
    }
    res += stol(char_stack);
    return res;
}

long sum = 0;
string S;
void dfs(int pos, string x)
{
    if (pos == S.size()) {
        sum += parse_eq(x);
        return;
    }

    dfs(pos+1, x + S[pos]);
    dfs(pos+1, x + '+' + S[pos]);
}

int main() {
    cin >> S;

    if (S.length() == 1) {
        cout << S << endl;
    } else {
        string s = "";
        s += S[0];

        dfs(1, s);

        cout << sum << endl;
    }
}
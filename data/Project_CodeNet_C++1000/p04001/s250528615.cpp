#include <bits/stdc++.h>
using namespace std;

/*
dfsで文字列を構築して、baseケースで文字列をパースして足す
*/

string S;
long long sum=0;

long long parse_eq(string x) {
    long long res = 0;
    string tmp = "";
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '+') {
            res += stoll(tmp);
            tmp = "";
        }
        else
        {
            tmp += x[i];
        }
    }
    res += stoll(tmp);
    return res;
}

void dfs(int pos, string x) {
    if (pos >= S.size()) {
        // parse add sum;
        sum += parse_eq(x);
        return;
    }

    // プラスを入れない
    dfs(pos+1, x+S[pos]);

    // プラスを入れる
    dfs(pos+1, x + '+' + S[pos]);
}

int main() {
    cin >> S;
    string c = "";
    dfs(1, c + S[0]);
    cout << sum << endl;
}
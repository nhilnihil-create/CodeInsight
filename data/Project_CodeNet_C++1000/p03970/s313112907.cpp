#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll MOD = 1e9 + 7;

int main()
{
    string s;
    cin >> s;

    string right_s = "CODEFESTIVAL2016";

    int answer = 0;
    for (int i = 0; i < int(s.size()); i++)
    {
        if (s.at(i) != right_s.at(i))
            answer++;
    }

    cout << answer << endl;
}
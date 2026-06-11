#include <bits/stdc++.h>
using namespace std;
//https://atcoder.jp/contests/arc061/tasks/arc061_a
typedef long long ll;
int main()
{
    string input;
    cin >> input;
    ll len = (input.length() - 1);
    ll res = stol(input);
    for (int bit = 1; bit < (1 << len); bit++)
    {
        ll temp = 0;
        for (ll i = 0; i < len; i++)
        {
            temp *= 10;
            temp += input.at(i) - '0';
            if (bit & (1 << i))
            {
                res += temp;
                temp = 0;
            }
        }
        temp *= 10;
        temp += input.at(len) - '0';
        res += temp;
    }
    cout << res << endl;
}
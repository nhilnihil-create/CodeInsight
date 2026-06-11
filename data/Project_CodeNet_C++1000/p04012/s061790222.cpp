// https://atcoder.jp/contests/abc044/tasks/abc044_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string w;
    cin >> w;
    vector<int> ctr(26, 0);
    for (int i = 0; i < w.size(); i++)
    {
        int j = w[i] - 'a';
        ctr[j] ^= 1;
    }
    int cond = 0;
    for (int i = 0; i < 26; i++)
    {
        cond += ctr[i];
    }
    cout << (cond ? "No" : "Yes") << endl;
    return 0;
}

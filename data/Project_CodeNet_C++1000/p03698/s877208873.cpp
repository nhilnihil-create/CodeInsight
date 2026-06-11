// https://atcoder.jp/contests/abc063/tasks/abc063_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<bool> used(26, false);

    for (int i = 0; i < s.size(); i++)
    {
        int j = s[i] - 'a';
        if (used[j])
        {
            cout << "no" << endl;
            return 0;
        }
        used[j] = true;
    }
    cout << "yes" << endl;
    return 0;
}

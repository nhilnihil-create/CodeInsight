#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;

    for (int o = N; o >= 0; o--)
    {
        bool satisfied = true;
        for (int i = 0; i < o; i++)
        {
            if (s.at(N - o + i) != t.at(i))
            {
                satisfied = false;
            }
        }
        if (satisfied)
        {
            cout << 2 * N - o << endl;
            return 0;
        }
    }
}
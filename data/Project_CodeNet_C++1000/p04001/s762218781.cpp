#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int size = S.size();

    long ans = 0;
    int index = 0;

    for (int i = 0; i < (1 << size - 1); i++)
    {
        index = size;
        bitset<9> s(i);
        for (int j = 0; j < size - 1; j++)
        {
            if (s.test(j))
            {
                ans += stol(S.substr(size - j - 1, index - (size - j - 1)));
                index = size - j - 1;
            }
        }

        ans += stol(S.substr(0, index));
    }

    cout << ans << endl;

    return 0;
}
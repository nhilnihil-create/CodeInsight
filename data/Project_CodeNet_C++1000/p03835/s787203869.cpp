#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, S;
    cin >> K >> S;

    int cnt = 0;
    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            int t = S - i - j;
            if (0 <= t && t <= K)
            {
                cnt++;
            }
        }
    }

    cout << cnt;
}
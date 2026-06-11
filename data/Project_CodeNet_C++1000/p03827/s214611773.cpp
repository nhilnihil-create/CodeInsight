#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int x = 0, res = 0;
    for (int i = 0; i < N; i++)
    {
        if (S.at(i) == 'I')
            x++;
        else
            x--;
        res = max(res, x);
    }
    cout << res << endl;
    return 0;
}

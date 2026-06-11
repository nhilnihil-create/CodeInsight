#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y, N, OX = 0, OY = 0;
    cin >> X >> Y >> N;
    vector<vector<bool>> v(X, vector<bool>(Y, false));
    for (int i = 0; i < N; i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        switch (a)
        {
        case 1:
            OX = max(x, OX);
            break;

        case 2:
            X = min(x, X);
            break;

        case 3:
            OY = max(y, OY);
            break;

        case 4:
            Y = min(y, Y);
            break;
        }
    }

    int ans = 0;
    for (int i = OX; i < X; i++)
    {
        for (int j = OY; j < Y; j++)
        {

            ans++;
        }
    }
    cout << ans;
    return 0;
}

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y, N;
    cin >> X >> Y >> N;
    vector<vector<bool>> v(X, vector<bool>(Y, false));
    for (int i = 0; i < N; i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        switch (a)
        {
        case 1:
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < Y; j++)
                {
                    v.at(i).at(j) = true;
                }
            }
            break;

        case 2:
            for (int i = x; i < X; i++)
            {
                for (int j = 0; j < Y; j++)
                {
                    v.at(i).at(j) = true;
                }
            }
            break;

        case 3:
            for (int i = 0; i < X; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    v.at(i).at(j) = true;
                }
            }
            break;

        case 4:
            for (int i = 0; i < X; i++)
            {
                for (int j = y; j < Y; j++)
                {
                    v.at(i).at(j) = true;
                }
            }
            break;
        }
    }

    int ans = X * Y;
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (v.at(i).at(j))
            {
                ans--;
            }
        }
    }
    cout << ans;
    return 0;
}

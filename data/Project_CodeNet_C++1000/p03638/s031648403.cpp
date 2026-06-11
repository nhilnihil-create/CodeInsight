#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int h, w;
    int n;
    cin >> h >> w >> n;

    vi data(n+1);

    for(int i = 1; i <= n; ++i)
    {
        cin >> data[i];
    }

    vector<vi> grid(h, vi(w));
    int color = 1;
    for(int j = 0; j < w; ++j)
    {
        if(j%2 == 0)
        {
            for(int i = 0; i < h; ++i)
            {
                if(data[color] == 0)
                {
                    ++color;
                }
                grid[i][j] = color;
                data[color]--;

            }
        }
        else
        {
            for(int i = h-1; i >= 0; --i)
            {
                if(data[color] == 0)
                {
                    ++color;
                }
                grid[i][j] = color;
                data[color]--;
            }
        }
    }

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}

#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w, n, x, y, a, m = 0;
    cin >> h >> w >> n;
    int d[h][w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) d[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> a;
        if (a == 1)
        {
            for (int j = 0; j < x; j++)
                for (int k = 0; k < w; k++) d[j][k]++;
        }
        else if (a == 2)
        {
            for (int j = x; j < h; j++)
                for (int k = 0; k < w; k++) d[j][k]++;
        }
        else if (a == 3)
        {
            for (int j = 0; j < h; j++)
                for (int k = 0; k < y; k++) d[j][k]++;
        }
        else
        {
            for (int j = 0; j < h; j++)
                for (int k = y; k < w; k++) d[j][k]++;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            if (d[i][j] == 0) m++;
    }
    cout << m;
}
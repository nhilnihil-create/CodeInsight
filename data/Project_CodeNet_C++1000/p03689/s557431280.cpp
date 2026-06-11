#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long H, W, h, w, s, a;
    cin >> H >> W >> h >> w;
    if (H % h == 0 && W % w == 0)
    {
        cout << "No";
        return 0;
    }
    a = 1000000000 / W / H;
    s = (h*w-1)*(-1)*a - 1;
    cout << "Yes" << "\n";
    for (int i = 0; i < H; i++)
    {
        for (int y = 0; y < W; y++)
        {
            if (i % h == h-1 && y % w == w-1)
            {
                cout << s << " ";
            }
            else
            {
                cout << a << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int H, W, d;
    cin >> H >> W >> d;

    char col_char[] = "RBGY";

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            int tx = x + y + H, ty = x - y + H;
            tx /= d;
            ty /= d;
            int idx = 0;
            idx = (tx % 2 == 0) ? 0 : 2;
            idx += (ty % 2 == 0) ? 0 : 1;
            cout << col_char[idx];
        }
        cout << endl;
    }

    return 0;
}

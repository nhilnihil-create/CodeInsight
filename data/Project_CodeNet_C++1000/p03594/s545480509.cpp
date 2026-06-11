#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
int h = 16, w = 16, d = 4;
vector<vector<int>> bd;
int ans = 0;

void rec(int x, int y)
{
    if (x == w) {
        rec(0, y + 1);
        return;
    }

    if (y == h) {
        ans++;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << bd[i][j] << " ";
            }
            cout << endl;
        }
        cout << "=====" << endl;
        return;
    }

    bool used[4] = {};

    for (int dx = -d; dx <= d; dx++) {
        int dy = d - abs(dx);

        int cx = x + dx;
        {
            int cy = y + dy;

            if (cx >= 0 && cx < w && cy >= 0 && cy < h) {
                if (bd[cy][cx] >= 0)
                    used[bd[cy][cx]] = true;
            }
        }
        {
            int cy = y - dy;

            if (cx >= 0 && cx < w && cy >= 0 && cy < h) {
                if (bd[cy][cx] >= 0)
                    used[bd[cy][cx]] = true;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (!used[i]) {
            bd[y][x] = i;
            rec(x + 1, y);
            bd[y][x] = -1;
        }
    }
}

int main()
{
    bd.resize(h, vector<int>(w, -1));

    rec(0, 0);

    cout << "*** " << ans << endl;

    // int h, w, d;
    // cin >> h >> w >> d;

    return 0;
}

*/

const char* col = "RYGB";

int main()
{
    int h, w, d;
    cin >> h >> w >> d;

    vector<string> bd(h, string(w, '.'));

    if (d % 2 == 1) {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                bd[y][x] = col[(x + y) % 4];
            }
        }
    } else {
        int bw = d;
        int bh = d - 1;

        for (int y = 0; y < h + 2 * bw; y++) {
            // continue;
            for (int x = 0; x < w + 2 * bw; x++) {
                int dx = x % bw;
                int dy = y % bw;
                int ph = (x / bw % 2) ^ (y / bw % 2);
                if (dy == bw - 1)
                    continue;

                int tx = dx >= bw / 2 ? bw - 1 - dx : dx;
                int ty = dy > bh / 2 ? bh - 1 - dy : dy;

                // if (ph != 0)
                //     continue;

                if (!(tx + ty < bh / 2)) {
                    int cx = x - bw;
                    int cy = y - bw;

                    if (cx >= 0 && cx < w && cy >= 0 && cy < h)
                        bd[cy][cx] = col[ph + 0];
                }
            }
        }

        for (int y = 0; y < h + 2 * bw; y++) {
            for (int x = 0; x < w + 2 * bw; x++) {
                int dx = x % bw;
                int dy = y % bw;
                int ph = (x / bw % 2) ^ (y / bw % 2);
                if (dy == bw - 1)
                    continue;

                int tx = dx >= bw / 2 ? bw - 1 - dx : dx;
                int ty = dy > bh / 2 ? bh - 1 - dy : dy;

                if (!(tx + ty < bh / 2)) {
                    int cx = x + bw / 2 - bw;
                    int cy = y + bw / 2 - bw;

                    if (cx >= 0 && cx < w && cy >= 0 && cy < h)
                        bd[cy][cx] = col[ph + 2];
                }
            }
        }
    }

    for (auto& row : bd) {
        cout << row << endl;
    }

    return 0;
}

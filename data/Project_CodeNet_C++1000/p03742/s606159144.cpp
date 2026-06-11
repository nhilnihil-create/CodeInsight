#include <bits/stdc++.h>
using namespace std;
#define mst(a, b) memset(a, b, sizeof(a))
typedef long long LL;
const int N = 150 + 10;

//int sg[N][N];
//
//int getSG(int x, int y) {
//    if (x == 0 && y == 0 || x == 1 && y == 0 || x == 0 && y == 1)
//        return 0;
//    if (~sg[x][y])
//        return sg[x][y];
//    bool vis[N];
//    mst(vis, false);
//    for (int i = 1; 2 * i <= x; i++)
//        vis[getSG(x - i * 2, y + i)] = true;
//    for (int i = 1; 2 * i <= y; i++)
//        vis[getSG(x + i, y - i * 2)] = true;
//    for (int i = 0; ; i++) if (!vis[i])
//        return sg[x][y] = i;
//}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);

//    mst(sg, -1);
//
//    for (int i = 0; i <= 10; i++) {
//        for (int j = 0; j <= 10; j++) if (!getSG(i, j))
//            cout << i << " " << j << "\n";
//    }

    LL x, y;

    cin >> x >> y;

    if (abs(x - y) <= 1)
        cout << "Brown" << "\n";
    else
        cout << "Alice" << "\n";

    return 0;
}

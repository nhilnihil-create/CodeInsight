#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int b[n], col[n];
    for (int i = 0; i < n; i++) {
        b[i] = 1;
        col[i] = 'w';
    }
    col[0] = 'r';
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        if (b[x] > 0) {
            if (b[y] == 0) {
                col[y] = col[x];
            }
            else if (col[x] == 'r') col[y] = 'r';
            b[x]--;
            b[y]++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += !!(b[i] > 0 && col[i] == 'r');
    }
    cout << cnt << "\n";
}

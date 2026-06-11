#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int p[N], mark[N];

int main()
{
    int n, k; cin >> n >> k;
    if (k == 1 || k == 2 * n - 1) return cout <<"No\n", 0;
    cout << "Yes\n";
    if (k == 2) {
        p[n] = 2;
        p[n-1] = 3;
        p[n+1] = 1;
        p[n+2] = 4;
        mark[1] = mark[2] = mark[3] = mark[4] = true;
    }
    else {
        p[n] = k;
        p[n-1] = k-1;
        p[n+1] = k+1;
        p[n+2] = k-2;
        mark[k-2] = mark[k-1] = mark[k] = mark[k+1] = true;
    }
    int pnt = 1;
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (!p[i]) {
            while (mark[pnt]) pnt++;
            p[i] = pnt++;
        }
        cout << p[i] << " ";
    }
    cout << "\n";

    return 0;
}

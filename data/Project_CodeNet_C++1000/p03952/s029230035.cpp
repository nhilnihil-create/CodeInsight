#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+7;

int a[MAXN];
int r[MAXN];

void placeAt(int x, int _x) {
    if (a[_x]==x) return;
    int y = a[_x];
    int _y = r[x];
    swap(a[_x], a[_y]);
    swap(r[x], r[y]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    int z = n+n;

    if (x==1||x==z-1) {
        cout << "No" << "\n";
        return 0;
    }

    for (int i = 1; i < z; i++) {
        a[i] = i;
        r[i] = i;
    }

    placeAt(x, n);
    placeAt(x-1, n-1);
    placeAt(x+1, n+1);
    if (x+2 < z) placeAt(x+2, n-2);
    if (x-2 > 0) placeAt(x-2, n+2);

    cout << "Yes\n";
    for (int i = 1; i < z; i++) cout << a[i] << "\n";

    return 0;
}

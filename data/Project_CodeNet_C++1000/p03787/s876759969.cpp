#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;
int n, m;
vector <int> e[MaxN];
int col[MaxN];
long long a, b, c;

bool bip(int x) {
    bool ret = true;
    for (int y : e[x]) {
        if (col[y] == 0) {
            col[y] = 3 - col[x];
            ret &= bip(y);
        } else if (col[y] == col[x])
            ret = false;
    }
    return ret;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[--x].push_back(--y);
        e[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (col[i]) continue;
        if (e[i].size() == 0)
           c++;
        else {
            col[i] = 1;
            if (bip(i))
                a++;
            else
                b++;
        }
    }
    cout << 2*a*a + b*b + 2*a*b + 2*c*n - c*c;
	return 0;
}
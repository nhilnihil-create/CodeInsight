#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/

int n, m;
int a[100000];
int imos[100000];

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 1; i < n; i++) {
        int cur = a[i - 1], next = a[i];
        if (cur + 2 < m) {
            imos[cur + 2]++;
        }
        if (cur < next) {
            if (next + 1 < m)
                imos[next + 1]--;
        } else {
            imos[1]++;
            imos[next + 1]--;
        }
    }
    for (int i = 0; i < m; i++) {
        // cout << imos[i] << endl;
    }
    for (int i = 1; i < m; i++) {
        imos[i] += imos[i - 1];
    }
    for (int i = 1; i < n; i++) {
        int cur = a[i - 1], next = a[i];
        if (cur < next) {
            if (next + 1 < m)
                imos[next + 1] -= next - cur - 1;
        } else {
            imos[next + 1] -= m - cur + next - 1;
        }
    }
    for (int i = 1; i < n; i++) {
        int cur = a[i - 1], next = a[i];
        if (cur > next) {
            imos[0] += m - cur - 1;
        }
    }
    int otk = imos[0];
    for (int i = 1; i < m; i++) {
        imos[i] += imos[i - 1];
        otk = max(otk, imos[i]);
    }
    for (int i = 0; i < m; i++) {
        // cout << imos[i] << endl;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int cur = a[i - 1], next = a[i];
        if (cur < next) {
            ans += next - cur;
        } else {
            ans += m - cur + next;
        }
    }
    cout << ans - otk << endl;
    return 0;
}
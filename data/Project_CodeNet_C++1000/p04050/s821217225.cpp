#include <bits/stdc++.h>
using namespace std;

int n,m,sum,cnt;
int a[110];
vector<int> b;
int main() {
    cin >> n >> m;
    int odd = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            swap(a[i], a[cnt++]);
        }
    }
    if (m == 1 && n == 1) {
        cout << "1\n1\n1\n";
        return 0;
    }
    if (m == 1) {
        cout << a[0] << endl;
        cout << 2 << endl;
        cout << a[0]-1 << " " << 1 << endl;
        return 0;
    }
    if (cnt > 2) {
        cout << "Impossible" << endl;
        return 0;
    }
    swap(a[1],a[m-1]);
    for (int i = 0; i < m; i++) cout << a[i] << " \n"[i == m-1];
    a[0]--; a[m-1]++;
    cout << m - (a[0] == 0) << endl;
    for (int i = 0 + (a[0] == 0); i < m; i++) cout << a[i] << " \n"[i == m-1];
    return 0;
}
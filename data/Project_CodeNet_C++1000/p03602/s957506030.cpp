#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long n, a[300][300];
struct Elem {
    int l;
    int u, v;
};
vector<Elem> v;
long long b[300][300];
long long ans = 0;
bool flag = true;
bool cc[300][300];

int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            b[i][j] = 0x7fffffff;
            b[i][j] <<= 10; 
            if (i == j) b[i][j] = 0;
            cin >> a[i][j];
//          a[i][j] = (i + j) % 10 + 3;
            if (i < j) {
                Elem e;
                e.l = a[i][j];
                e.u = i;
                e.v = j;
                v.push_back(e);
            }   
        }   
    }   
    sort(v.begin(), v.end(), [](const Elem p, const Elem q) -> bool { return p.l < q.l; }); 
    for (Elem e : v) {
        if (b[e.u][e.v] < e.l) {
            flag = false;
            break;
        } else if (b[e.u][e.v] > e.l) {
            ans += e.l;
            for (int u = 0; u < n; u ++) {
                for (int v = 0; v < n; v ++) {
                    if (!cc[u][v] && b[u][v] > b[u][e.u] + e.l + b[v][e.v]) {
                        b[u][v] = b[v][u] = b[u][e.u] + e.l + b[v][e.v];
                    }   
                }   
            }   
            cc[e.u][e.v] = 1;
        }   
    }   
    if (!flag) cout << -1 << endl;
    else cout << ans << endl;

return 0;
}
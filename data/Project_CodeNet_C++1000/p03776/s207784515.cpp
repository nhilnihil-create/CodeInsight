#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<long long int>> m;

long long int myc(int a, int b) {
    if (a < b) return 0;
    if (b == 1) return a;
    if (a == b) return 1;
    if (m[a][b] == -1) {
        m[a][b] = myc(a - 1, b - 1) + myc(a - 1, b);
    }
    return m[a][b];
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    m = vector<vector<long long int>> (n + 1, vector<long long int>(n + 1, -1));
    vector<long long int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<long long int>());
    int flag = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            flag++;
        } else{
            break;
        }
    }
    if (flag >= a) {
        cout << v[0] << endl;
        long long int res = 0;
        for (int i = a; i <= min(b, flag); i++) {
            res += myc(flag, i);
        }
        cout << res << endl;
        return 0;
    }
    int c1 = 0, c2 = 0;
    long long int s = 0;
    for (int i = 0; i < n; i++) {
        if (i < a) s += v[i];
        if (i < a && v[i] == v[a - 1]) c1++;
        if (i >= a && v[i] == v[a - 1]) c2++;
    }
    cout << setprecision(15) << s * 1.0 / a << endl;
    // c(c1 + c2, c1);
    cout << myc(c1 + c2, c1) << endl;
}

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> c(n+1, 0);
    int a[n]; for (int i = 0; i < n; i++) { cin >> a[i]; c[a[i]]++; }
    int mn = *min_element(a, a+n), mx = *max_element(a, a+n);
    bool ans = mn == (mx + 1) / 2 && (mx % 2 ? c[mn] == 2 : c[mn] == 1);
    for (int i = mn+1; i <= mx; i++) ans = ans && c[i] >= 2;
    cout << (ans ? "Possible\n" : "Impossible\n");
}

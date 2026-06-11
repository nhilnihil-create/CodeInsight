#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n; cin >> n;
    vector<int> a(n), b; b.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1) b.emplace_back(i);
    }

    if (n == 1) {
		cout << a[0] << '\n';
        if (a[0] == 1) cout << "1\n1";
        else cout << "2\n1 " << a[0] - 1;
        return 0;
    }
    if (b.size() > 2) return cout << "Impossible\n", 0;

    if (b.size() > 0) swap(a[0], a[b[0]]);
    if (b.size() > 1) swap(a[n-1], a[b[1]]);

    for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << '\n';
    cout << n - (a[0] == 1) << '\n';
    if (a[0] > 1) cout << a[0] - 1 << ' ';
    for (int i = 1; i < n-1; ++i) cout << a[i] << ' ';
    cout << a[n-1] + 1 << endl;
    return 0;
}

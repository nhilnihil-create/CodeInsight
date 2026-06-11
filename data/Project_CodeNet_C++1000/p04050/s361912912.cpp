#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> a, b;
vector<int> o;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        if (x%2 == 1)
            o.push_back(x);
        else
            a.push_back(x);
    }

    if (n%2 == 1 && o.size() > 1) {
        cout << "Impossible\n";
        return 0;
    } if (n%2 == 0 && o.size() > 2) {
        cout << "Impossible\n";
        return 0;
    }

    if (o.size() == 1) {
        a.push_back(o[0]);
    } if (o.size() == 2) {
        a.insert(a.begin(), o[0]);
        a.push_back(o[1]);
    }

    if (m == 1) {
        b.push_back(1);
        if (n != 1)
            b.push_back(n - 1);
    } else {
        for (int i = 0; i < m; ++i) {
            if (i == 0) {
                if (a[i]%2 == 1)
                    b.push_back(a[i]+1);
                else {
                    b.push_back(1);
                    b.push_back(a[i]);
                }
                continue;
            }

            if (i == m-1) {
                if (a[i] != 1)
                    b.push_back(a[i]-1);
                continue;
            }

            b.push_back(a[i]);
        }
    }

    for (int i = 0; i < m; ++i)
        cout << a[i] << ' ';
    cout << "\n";
    cout << b.size() << "\n";

    for (int i = 0; i < b.size(); ++i)
        cout << b[i] << ' ';
    cout << endl;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    if(a[n - 1] - a[0] > 1) {
        cout << "No" << endl;
        return 0;
    }
    int uniq = count(all(a), a[0]);
    int all = count(all(a), a[n - 1]);
    if(a[0] == a[n - 1]) {
        if(a[0] == n - 1 || 2 * a[0] <= n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if(uniq > a[n - 1]) {
            cout << "No" << endl;
        } else {
            if(2 * (a[n - 1] - uniq) <= all && a[n - 1] - uniq > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}

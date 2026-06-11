#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n;
    cin >> n;
    int t[n], a[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    } 
    ll T = t[0];
    ll A = a[0];
    for (int i = 1; i < n; i++) {
        ll t_hiritu = T/t[i];
        ll a_hiritu = A/a[i];
        if (T%t[i]) t_hiritu++;
        if (A%a[i]) a_hiritu++;
        ll hiritu = (t_hiritu > a_hiritu) ? t_hiritu : a_hiritu;
        T = t[i] * hiritu;
        A = a[i] * hiritu;
    }
    cout << T + A << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int mod = 1'000'000'007;

int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> d_t(n, - 1);
    vector<int> d_a(n, - 1);
    d_t[0] = t[0];
    d_a[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++){
        if (t[i] != t[i - 1]) d_t[i] = t[i];
    }
    for (int i = n - 2; i >= 0; i--){
        if (a[i] != a[i + 1]) d_a[i] = a[i];
    }
    vector<int> merges(n, - 1);
    bool flag = true;
    for (int i = 0; i < n; i++){
        if (d_t[i] != - 1 && d_a[i] != - 1){
            if (d_t[i] != d_a[i]) flag = false;
            else merges[i] = 1;
        }
        else if (d_t[i] != - 1) {
            if (t[i] > a[i]) flag = false;
            else merges[i] = 1;
        }
        else if (d_a[i] != - 1){
            if (a[i] > t[i]) flag = false;
            else merges[i] = 1;
        }
    }
    if (!flag){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (merges[i] == - 1) merges[i] = min(t[i], a[i]);
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) ans *= merges[i], ans %= mod;
    cout << ans << endl;
}

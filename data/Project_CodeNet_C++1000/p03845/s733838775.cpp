#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> t(n);
    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        total += t[i];
    }
    int m; cin >> m;
    vector<int> p(m), x(m);
    for(int i = 0; i < m; i++) {
        cin >> p[i] >> x[i];
        cout << total - t[p[i]-1] + x[i] << endl;
    }
    return 0;
}
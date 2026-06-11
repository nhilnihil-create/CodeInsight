#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m, p, x, sum = 0;
    cin >> n;
    vector<int> t(n);
    for (int i=0; i<n; i++) cin >> t[i];
    sum = accumulate(t.begin(), t.end(), 0);
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> p >> x;
        cout << sum - t[p-1] + x << endl;
    }
    return 0;
}
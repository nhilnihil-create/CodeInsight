#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> T(n);
    for (int i=0; i<n;i++){
        cin >> T.at(i);
    }
    int m;
    cin >> m;
    long long sum = 0;
    for (int i=0; i<m; i++){
        int p, x, buf;
        cin >> p >> x;
        p--;
        buf = T.at(p);
        T.at(p) = x;
        for (int j=0; j<n; j++) sum += T.at(j);
        cout << sum << endl;
        T.at(p) = buf;
        sum = 0;
    }
    return 0;
}
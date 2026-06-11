#include <bits/stdc++.h>
using namespace std;
#define int long long

int my_gcd(int n, int m){
    if(n < m) swap(n, m);
    if(m == 0) return n;
    else return my_gcd(m, n%m);
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> t(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    int l = t[0];
    for(int i=1; i<n; i++){
        int g = my_gcd(l, t[i]);
        l = l / g * t[i];
    }
    cout << l << endl;

    return 0;
}
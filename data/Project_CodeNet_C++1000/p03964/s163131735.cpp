#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> t(n), a(n);
    for(int i=0; i<n; i++){
        cin >> t[i] >> a[i];
    }

    long long int takahashi = t[0], aoki = a[0];
    for(int i=1; i<n; i++){
        long long int coeff = max((takahashi + t[i] - 1) / t[i], 
                                  (aoki      + a[i] - 1) / a[i]);
        takahashi = coeff * t[i];
        aoki      = coeff * a[i];
    }
    cout << takahashi + aoki << endl;
    return 0;
}
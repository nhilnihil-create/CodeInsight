#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<long long> v;
    for(int i = 0; i < n; i++) {
        long long d = a[i] / b[i];
        if(a[i] % b[i] != 0) {
            d++;
        }
        v.push_back(d * b[i] - a[i]);
    }
    for(int i = n - 1; i > 0; i--) {
        if(v[i] > v[i-1]) {
            long long d = (v[i] - v[i-1]) / b[i-1];
            if((v[i] - v[i-1]) % b[i-1] != 0) {
                d++;
            }
            v[i-1] += d * b[i-1];
        }
    }
    cout << v[0] << "\n";
}
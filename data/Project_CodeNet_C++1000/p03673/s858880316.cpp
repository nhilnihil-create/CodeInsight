#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++) {
        if(i % 2 == 0) {
            b[i/2] = a[n-1-i];
        }
        else {
            b[n-1-i/2] = a[n-1-i];
        }
    }

    for(int i=0; i<n; i++) {
        if(i) cout << " ";
        cout << b[i];
    }
    cout << endl;
}
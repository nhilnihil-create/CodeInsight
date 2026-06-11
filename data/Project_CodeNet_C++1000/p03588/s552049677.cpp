#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
  	vector<ll> a(n),b(n);
    ll m = 0,key;
    for(int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
        if(a[i] > m) {
            m = a[i];
            key = i;
        }
    }
    cout << a[key] + b[key] << endl;
}
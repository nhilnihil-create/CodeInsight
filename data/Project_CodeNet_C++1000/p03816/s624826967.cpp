#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a;
    vector<ll> b(100010);
    for (int i=0;i<n;i++) {
        cin >> a;
        b[a]++;
    }
    ll k=0;
    int r=0;
    for (int i=0;i<100010;i++) {
        if (b[i]>1) {
            if (r==1) b[i]--;
            k+=b[i]/2;
            r=(b[i]+1)%2;
        } 
    }
    cout << n-2*k << endl;
}
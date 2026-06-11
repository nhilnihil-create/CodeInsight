#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    ll a[3]; rep(i,3) cin >> a[i];
    if(a[0]%2 == 0 ||a[1]%2 == 0 ||a[2]%2 == 0 ) cout << 0;
    else {
        sort(a,a+3);
        cout << (a[0]*a[1]);
    }
    

    return 0;
}
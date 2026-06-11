#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;
    //1Lの最小金額
    ll l = min(s,min(2*h,4*q));
    ll a = min(l*2,d);
    cout << n/2*a+n%2*l << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll q, h, s, d; cin >> q >> h >> s >> d;
    ll n;   cin >> n;

    ll X = min(2*min(2*q, h), s);
    ll XL = min(2*X, d);
    
    cout << n%2*X+n/2*XL << endl;

    
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main( ){
    ll x,i,j,k,s = 0;
    cin >> x;
    s += ((x / 11) * 2);
    j = x % 11;
    if (j <= 6 && j > 0) {
        s++;
    }
    else if (j > 0) {
        s += 2;
    }
    cout << s << '\n';
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a % 2 && b % 2 && c % 2){
        cout << min({a*b, b*c, c*a}) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
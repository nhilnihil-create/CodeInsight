#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ll x;
    cin >> x;
    if(x % 11 > 6) cout << 2 * (x / 11) + 2 << endl;
    else if(x % 11 > 0) cout << 2 * (x / 11) + 1 << endl;
    else if(x % 11 == 0) cout << 2 * (x / 11) << endl;
    return 0;
}
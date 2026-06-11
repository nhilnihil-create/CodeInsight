#include <iostream>
#define ll long long
using namespace std;

int main(){
    ll x, a, b;
    cin >> x >> a >> b;
    if(x < b - a) cout << "dangerous" << endl;
    else if (a >= b) cout << "delicious" << endl;
    else cout << "safe" << endl;
    return 0;
}
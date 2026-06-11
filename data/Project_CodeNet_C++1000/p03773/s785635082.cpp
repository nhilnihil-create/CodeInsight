#include <iostream>
#define ll long long
using namespace std;

int main(){
    ll a, b;
    cin >> a >> b;
    ll c = a + b;
    if(c > 23) c -= 24;
    cout << c << endl;
    return 0;
}
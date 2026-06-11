#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long x,y;
    cin >> x >> y;
    if(abs(x-y)>=2) cout << "Alice";
    else cout << "Brown";
    cout << endl;
}
#include <iostream>
using namespace std;
int main()
{
    long long int a, b, x, div;
    cin >> a >> b >> x;
    if(a == 0) {
        div = b / x;
        div = div + 1;
        cout << div;
    } else {
        div = b / x;
        div = div - (a - 1) / x;
        cout << div;
    }
}
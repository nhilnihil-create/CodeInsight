#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c, d, e, f, g;
int main(void){
    // Your code here!
    cin >> a >> b >> c >> d >> e >> f >> g;
    if (a == 0 || d == 0 || e == 0){
        cout << a - a % 2 + b + d - d % 2 + e - e % 2 << endl;
        return 0;
    }
    cout << a + b + d + e - (a % 2 + d % 2 + e % 2 == 1 || a % 2 + d % 2 + e % 2 == 2 ? 1 : 0) << endl;
}

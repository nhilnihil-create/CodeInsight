#include <iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = (b > d) ? d : b;
    ans -= (a > c) ? a : c;
    if(ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}
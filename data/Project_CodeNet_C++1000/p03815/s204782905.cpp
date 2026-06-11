#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long X; cin >> X;
    long long ans = 0;
    ans += X/11*2;
    X %= 11;
    if(X > 6) cout << ans + 2 << endl;
    else if(X != 0) cout << ans + 1 << endl;
    else cout << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    
    long long int ans = (long long int)b*(n-1)+a
    - ((long long int)a*(n-1)+b) + 1;
    if(ans >= 1) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}
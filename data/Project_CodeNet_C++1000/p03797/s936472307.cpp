#include <iostream>
using namespace std;

int main(){
    long long int n, m;
    cin >> n >> m;
    long long int ans;

    if(n*2 > m) ans = m/2;
    else{
        ans = n;
        m -= n*2;
        ans += m/4;
    }
    cout << ans << endl;
    return 0;
}
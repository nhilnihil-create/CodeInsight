#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void){
    long long a,b,x;
    cin >> a >> b >> x;
    long long ans = (b / x) - (a - 1) / x;
    if(a == 0){
        ans = b / x + 1;
    }
    cout << ans << endl;
}

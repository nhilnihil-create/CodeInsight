#include <iostream>
#include <vector>

using namespace std;
int main(void){
    long long q,h,s,d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;
    
    long long ans = min(q * 8,min(4 * h,min(s * 2,d))) * (n / 2);
    ans += (n % 2 == 1) ? min(q * 4,min(h * 2,s)) : 0;
    
    cout << ans << endl;
    
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    long a,b,c;
    cin >> a >> b >> c;
   long ta,tb,tc; 
   long ans = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
        if(a == b && b == c){
            ans = -1;
            break;
            }
        ta = (b + c) / 2;
        tb = (a + c) / 2;
        tc = (a + b) / 2;
        a = ta;
        b = tb;
        c = tc;
        ans++;
    }
    cout << ans << endl;
}

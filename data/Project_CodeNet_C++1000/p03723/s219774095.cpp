#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a,b,c;
    int tmpA,tmpB,tmpC;
    int ans = 0;
    cin >> a >> b >> c;
    if(!(a%2 == 0 && b%2 == 0 && c%2 == 0)){
        cout << 0;
    }else {
        while (!(a == b && b == c) && (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)) {
            ans++;
            tmpA = a;
            tmpB = b;
            tmpC = c;
            a = tmpB / 2 + tmpC / 2;
            b = tmpC / 2 + tmpA / 2;
            c = tmpA / 2 + tmpB / 2;
        }
        if (a == b && b == c) cout << -1;
        else cout << ans;
    }


    return 0;
}
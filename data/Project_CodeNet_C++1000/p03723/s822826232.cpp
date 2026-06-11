#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, c;
    cin >> a >> b >> c;

    long long int ans = 0;
    while(1){
        //cout << a << " " << b << " " << c << endl;
        if(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) ans += 1;
        else break;

        if(a == b && b == c){
            cout << -1 << endl;
            return 0;
        }
        long long int na = b / 2 + c / 2;
        long long int nb = c / 2 + a / 2;
        long long int nc = a / 2 + b / 2;

        a = na;
        b = nb;
        c = nc;
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {

    int a,b,c; cin >> a >> b >> c;
    int d = a%b;
    int s = d;

    while(1){
        if(d == c) break;
        else{
            d += s;
            d %= b;
            if(d == s) break;
        };
    }

    cout << ((d == c)?"YES":"NO");

    return 0;
}










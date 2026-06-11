#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

bool is_integer(double x){
    return std::floor(x) == x;
}

int main(){
    ll pay = 0;
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    q *= 4; h *= 2;
    if(n % 2 == 1){
        pay = min({q, h, s});
        n--;
    }

    if(n == 0){
        cout << pay << endl;
        return 0;
    }

    q *= 2; h *= 2; s *= 2;
    pay += min({q, h, s, d}) * (n / 2);

    cout << pay << endl;
 }
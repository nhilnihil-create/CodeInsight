#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    ll p05 = min(2*Q, H), p10 = min(2*p05, S), p20 = min(2*p10, D);

    ll price = 0;
    while(N!=0){
        if (N >= 2){
            price += (N/2)*p20;
            N %= 2;
        }
        else {
            price += (N/1)*p10; 
            N %= 1;
        }
    }

    cout << price << endl;
    return 0;
}
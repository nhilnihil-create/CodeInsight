#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll qrt, hlf,sgl,dbl;
    ll n;
    cin >> qrt >> hlf >> sgl >> dbl >> n;
    ll sum = 0;
    if(dbl > 8 * qrt)
    dbl = 8 * qrt;
    if(dbl > 4 * hlf)
    dbl = 4 * hlf;
    if(dbl > 2 * sgl)
    dbl = 2 * sgl;
    if(sgl > 4 * qrt)
    sgl = 4 * qrt;
    if(sgl > 2 * hlf)
    sgl = 2 * hlf;
    while(n){
        if(n >= 2){
            sum += n / 2 * dbl;
            n -= n / 2 * 2;
        }
        if(n == 1){
            n--;
            sum += sgl;
        }
    }
    cout << sum << endl;
}
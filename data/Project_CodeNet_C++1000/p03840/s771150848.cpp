#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll mino(ll &x){
    if(x<=2)return 0;
    ll tmp = (x-1)/2*2;
    x -= tmp;
    return tmp;
}

int main(){

    ll I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ll ans = O + mino(I) + mino(J) + mino(L);
    if(I > J)swap(I, J);
    if(J > L)swap(J, L);
    if(I > J)swap(I, J);
    if(I == 2)ans += 6;
    else if(J == 2)ans += 4;
    else if(I == 1)ans += 3;
    else if(L == 2)ans += 2;
    cout << ans << endl;

    return 0;
}
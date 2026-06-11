#include <bits/stdc++.h>
using namespace std;

#define rep(i,n,m) for(ll (i)=(n);(i)<(m);(i)++)
#define rrep(i,n,m) for(ll (i)=(n);(i)>(m);(i)--)
using ll = long long;
const ll MOD = 1e9+7;

int main(){

    int N;
    cin >> N;

    ll Amin,Bmin = 1e9+1 ,A,B;

    rep(i,0,N){
        cin >> A >> B;
        if (Bmin > B){
            Amin = A;
            Bmin = B;
        }
    }

    cout <<( Amin + Bmin )<< endl;

    return 0;
}
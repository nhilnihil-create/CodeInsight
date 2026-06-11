#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    ll b = abs(A - B);
    bool o = false;
    for(ll i=0; i<N-1; i++){
        ll p = i, m = N-1 - i;
        ll n = C*p - D*m, x = D*p - C*m;
        if(n <= b&&b <= x){
            o = true;
        }
    }
    if(o){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}


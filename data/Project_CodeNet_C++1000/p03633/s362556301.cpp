#include <bits/stdc++.h>
using namespace std;
using vl = vector<long long>;
using ll = unsigned long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else{
//        if(b>a) swap(a,b);
        return gcd(b,a%b);
    }
}

ll lcm(ll a, ll b){
    ll d = gcd(a,b);
    if(d == b) return a;
    return a/d*b;
}

int main(){
    int n; cin >> n;
    vl t(n);
    for(int ix=0;ix<n;ix++) cin >> t.at(ix);

    ll a = t.at(0), b;
    for(int ix=1;ix<n;ix++){
        b = t.at(ix);
        a = lcm(a,b);
    }
    cout << a << endl;
}
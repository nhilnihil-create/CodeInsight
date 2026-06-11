#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0)return a;
    return gcd(b,a%b);
}


int main(){
    ll N,X;cin >> N >> X;

    cout << 3*(N - gcd(N,X)) << endl;

    return 0;
}
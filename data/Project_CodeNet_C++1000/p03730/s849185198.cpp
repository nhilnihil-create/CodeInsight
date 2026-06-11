#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = (a * b)/gcd(a,b);
    return ret;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = gcd(a, b);
    
    if(c % g != 0) cout << "NO" << endl;
    else cout << "YES" << endl; 
    return 0;
}

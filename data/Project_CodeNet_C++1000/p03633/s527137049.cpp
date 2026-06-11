#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

ll gcd(ll a, ll b){
    if(b==0)
        return a;
    else
        return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;
    ll lcm;
    cin >> lcm;
    rep(i, n-1){
        ll val;
        cin >> val;
        lcm = lcm / gcd(lcm, val) * val;
    }
    cout << lcm << endl;
    return 0;
}
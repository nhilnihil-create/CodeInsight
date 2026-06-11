#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    ll q,h,s,d,n,one;
    cin >> q >> h >> s >> d;
    cin >> n;
    one = min({4*q,2*h,s});
    if(n%2 == 0){
        cout << min({one*n,d*n/2}) << endl;
    }else{
        cout << min({one*n,d*(n/2)+one}) << endl;
    }
    return 0;
}
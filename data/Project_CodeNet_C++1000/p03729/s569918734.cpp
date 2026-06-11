#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    string a,b,c; cin >> a >> b >> c;
    if(a[a.length()-1] == b[0] && b[b.length()-1] == c[0]){
        cout << "YES";
    }else{
        cout << "NO";
    }
}


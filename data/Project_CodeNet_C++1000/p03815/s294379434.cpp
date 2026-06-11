#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = +100100100;
typedef pair<ll,ll> P;
const ll MO = 1000000007;


int main(){
    ll n;
    cin >> n;
    if(n<=6){
        cout << 1 << endl;
        return 0;
    }else{
        ll a,b;
        a = ceil((double)n/11.0);
        b = a-1;
        if(a*6+b*5>=n){
            cout << a+b << endl;
            return 0;
        }else{
            cout << a + b+ 1 << endl;
            return 0;
        }
        // b = ceil((double)(n-6*a)/5.0);
        // cout << a << " b" << b << endl;
        // cout << a+b<<endl;
        // return 0;
    }
    
}
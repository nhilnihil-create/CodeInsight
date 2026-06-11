/*
      author  : nishi5451
      created : 12.08.2020 23:10:24
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

ll mod = 1000000007;

ll m_factorial(ll n){
    ll res = 1;
    for(int i=1; i<=n; i++)
        res = (res*i)%mod;
    return res;
}

int main(){
    ll n;
    cin >> n;
    cout << m_factorial(n) << endl;
    return 0;
}
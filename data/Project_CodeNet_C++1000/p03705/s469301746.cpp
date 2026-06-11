#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, a, b;
    ll f, l;
    cin >> n >> a >> b;

    f = a * (n - 1) + b;
    l = a + b * (n - 1);

    if(l - f + 1 < 0) put(0);
    else put(l - f + 1);
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll s = min({a*b,b*c,c*a});
    if(a%2 == 0 || b%2 == 0 || c%2 == 0) cout << 0 << endl;
    else cout << s << endl;
}
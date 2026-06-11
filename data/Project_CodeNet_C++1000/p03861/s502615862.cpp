#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    ll a,b,x;
    cin >> a >> b >> x;

    ll db = b/x;
    ll da = a/x;
    ll ans = db-da;
    if(a%x == 0) ans++;

    cout << ans << endl;
}
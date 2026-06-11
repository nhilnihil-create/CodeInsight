#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(){
    ll a, b, c, ans = -1;
    cin >> a >> b >> c;
    if(a*b*c % 2 == 0)ans = 0;
    else ans = min(a*b, min(b*c, c*a));
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007
 
int main(){
    ll x,y;
    cin >> x >> y;
    ll num = INF;
    ll a = y - x;
    if(a>=0) num = min(num,a);
    ll b = y + x + 1;
    if(b>=0) num = min(num,b);
    ll c = - y - x + 1;
    if(c>=0) num = min(num,c);
    ll d = -y + x + 2;
    if(d>=0) num = min(num,d);
    cout << num << endl;
    return 0;
}
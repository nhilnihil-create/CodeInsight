#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,n) for(int i=0 ; i < (int) (n) ; ++i )

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a,b,c;
    cin >> a >> b >> c;
    if (a%2==0 || b%2==0 || c%2==0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << min(a * b, min(a * c, b * c)) << endl;
    }
    
}



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;
int main(){
    ll n,m;
    string s;
    cin >> n >> m;
    ll ans=0LL;
    if (m >= 2*n) {
        ans+=n;
        m-=2*n;
        if (m >= 4 ) ans+=m/4;
    }
    else{
        ans+=m/2;
    }
    cout << ans << endl;
    return 0;
}
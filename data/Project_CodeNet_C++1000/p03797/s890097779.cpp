#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;

int main() {

    ll n,m ;
    cin >> n >> m ;

    if(m==1){
        cout << 0 << endl ;
        return 0 ;
    }
    ll ans = min(m/2,n) ;
    ll tmpc = m-ans*2 ;
    ans+= tmpc/4 ;


    cout << ans << endl ;

    return 0 ;
}

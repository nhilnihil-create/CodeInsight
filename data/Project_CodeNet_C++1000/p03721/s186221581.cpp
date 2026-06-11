#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;

int main() {

    ll n,k ;
    cin >> n >> k ;
    vector<ll> vec(100001) ;
    for(int i=0;i<n;++i){
        ll a,b ;
        cin >> a >> b ;
        vec[a]+=b ;
    }
    
    ll sum = 0 ;
    for(int i=1;i<100001;++i){
        sum+=vec[i];
        //cout << sum << endl ;
        if(sum>=k){
            cout << i << endl ;
            break ;
        }
    }

    return 0 ;
}

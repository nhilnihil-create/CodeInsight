#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
const int MOD = 1000000007;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    ll n; cin >> n;
    vector<ll> so(1e3);
    for(ll i = 1;i <= n;i++){
        ll I = i;
        for(ll j=2;j*j<=i;j++){
            while(I % j == 0){
                so[j]++;
                I /= j;
            }
            so[j] %= MOD;
        }
        if(I != 1) so[I]++;
    }
    ll ans = 1;
    for(int i=0;i<1e3;i++){
        if(so[i] > 0){
            ans *= (so[i]+1);
            ans %= MOD;
    }
    }
    cout << ans << endl;
}
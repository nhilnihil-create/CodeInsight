#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> x(n);
    for(ll i=0;i<n;i++) cin>>x[i];
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ll dis=x[i+1]-x[i];
        if(dis<=b/a){
            ans+=dis*a;
        }else{
            ans+=b;
        }
    }
    cout<<ans<<endl;

}
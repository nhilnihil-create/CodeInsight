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
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
ll frac[1001001];


int main(){
    int n,m;
    cin>>n>>m;
    frac[0]=1;
    for(int i=1;i<=n+m;i++){
        frac[i]=frac[i-1]*i;
        frac[i]%=MOD;
    }
    if(abs(n-m)>1){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    if(abs(n-m)==1){
        ans*=frac[n];
        ans%=MOD;
        ans*=frac[m];
        ans%=MOD;
    }else{
        ans*=frac[n];
        ans%=MOD;
        ans*=frac[m];
        ans%=MOD;
        ans*=2;
        ans%=MOD;
    }
    cout<<ans<<endl;

}
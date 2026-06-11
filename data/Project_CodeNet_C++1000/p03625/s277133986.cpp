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
const ll INF=9999999999;
int dpl[3010][3010];
int dpr[3010][3010];

int main(){
    int n;
    cin>>n;
    map<ll,ll> mp;
    vector<ll> canuse(0);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        mp[a]++;
        if(mp[a]==2) canuse.push_back(a);
        if(mp[a]==4) canuse.push_back(a);
    }
    if(canuse.size()<2){
        cout<<0<<endl;
        return 0;
    }
    sort(canuse.begin(),canuse.end(),greater<ll>());
    ll ans=canuse[0]*canuse[1];
    cout<<ans<<endl;

}
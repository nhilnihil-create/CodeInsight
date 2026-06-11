#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int W,H;
    cin>>W>>H;
    
    vector<pii> nums(H+W);
    rep(i,W) cin>>nums[i].first,nums[i].second=0;
    rep(i,H) cin>>nums[i+W].first,nums[i+W].second=1;
    
    W++,H++;
    sort(all(nums));
    ll sum=0;
    for(auto p:nums){
        if(p.second) sum+=W*p.first,H--;
        else sum+=H*p.first,W--;
    }
    cout1(sum);
}
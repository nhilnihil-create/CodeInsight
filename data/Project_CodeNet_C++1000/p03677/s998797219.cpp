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

#define rep(i,a) for(int i=0; i<a; i++)
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

int N, M, nums[100009];
ll s[200009], v[200009], val[200009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    rep(i,N) cin>>nums[i];
    
    mem(s,0); mem(v,0), mem(val,0);
    ll total=0;
    rep(i,N-1){
        int pre=nums[i], nxt=nums[i+1]+(nums[i+1]<pre?M:0);
        int dist=nxt-pre;
        total+=dist;
        if(dist>1){
            v[pre+2]++;
            v[nxt+1]--;
            s[nxt+1]-=(dist-1);
        }
    }
    
    rep1(i,2*M){
        v[i]+=v[i-1];
        s[i]+=s[i-1]+v[i];
        val[i]=s[i];
    }
    
    ll mx=0;
    rep1(i,M){
        if(mx<val[i]+val[i+M]) mx=val[i]+val[i+M];
    }
    cout1(total-mx);
}
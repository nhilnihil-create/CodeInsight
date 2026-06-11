#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define MAX 510000
#define INF 1<<30
#define LINF (ll)1<<62
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n,W; cin >> n >> W;
    vvl v(4);
    ll mn = 0;
    rep(i,n){
        ll a,b; cin >> a >> b;
        if(i==0) mn = a;
        v[a-mn].push_back(b);
    }
    rep(i,4) sort(rall(v[i]));
    rep(i,4){
        rep(j,(ll)v[i].size()-1){
            v[i][j+1] += v[i][j]; 
        }
    }
    ll ans = 0;
    rep(i,v[0].size()+1){
        rep(j,v[1].size()+1){
            rep(k,v[2].size()+1){
                rep(l,v[3].size()+1){
                    if(i*mn + j*(mn+1) + k*(mn+2) + l*(mn+3) > W) continue;
                    else{
                        ll sum = 0;
                        if(i!=0) sum += v[0][i-1];
                        if(j!=0) sum += v[1][j-1];
                        if(k!=0) sum += v[2][k-1];
                        if(l!=0) sum += v[3][l-1];
                        ans = max(ans, sum);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
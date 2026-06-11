#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n; cin >> n;
    vl p(n);
    rep(i,n){
        ll t; cin >> t; t--;
        p[t] = i+1;
    }
    vl a(n),b(n);
    ll num = 2;
    a[0] = 1;
    REP(i,1,n){
        if(p[i] < p[i-1]) a[i] = num;
        else{
            num += p[i] - p[i-1];
            a[i] = num;
        }
        num++;
    }
    for(auto i : a) cout << i << " ";
    cout << endl;
    b[n-1] = 1;
    ll sum = b[n-1] + a[n-1];
    for(ll i=n-2; i>=0; i--){
        b[i] = sum + p[i] - p[i+1] - a[i];
        sum = b[i] + a[i];
    }
    for(auto i : b) cout << i << " ";
    cout << endl;
}

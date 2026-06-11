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
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;



int main(){
    ll n,x; cin >> n >> x;
    if(x == 1 || x == 2*n-1) puts("No");
    else{
        puts("Yes");
        vl py(2*n-1);
        py[n-1] = x;
        rep(i,2*n-1){
            py[(n-1+i)%(2*n-1)] = (x-1+i)%(2*n-1) + 1;
        }
        rep(i,2*n-1){
            cout << py[i] << endl;
        }
    }
}
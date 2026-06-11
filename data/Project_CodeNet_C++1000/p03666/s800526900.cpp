#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF 1LL<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;
const int mod = 1e9 + 7;

int main(){
    ll n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    b = b-a;
    double center = (c+d)/(double)2.0;
    double dist = center*2;
    double e = (n-1)*(d-c)/2.0;
    double t = center*(n-1);
    //cout << center << " " << e << " " << t << endl;
    rep(i,n-1){
        //cout << t-e << " " << t+e << endl;
        if(t-e<=b && b<=t+e){
            puts("YES");
            return 0;
        }
        t -= dist;
    }
    puts("NO");
}
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
    vl a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % (n*(n+1)/2) != 0) puts("NO");
    else{
        ll cnt = sum / (n*(n+1)/2);
        ll counter = cnt;
        ll dis = a[0] - a[n-1];
        if((cnt - dis) % n != 0 || cnt - dis < 0){
            puts("NO");
            return 0;
        }
        counter -= (cnt - dis) / n;
        rep(i,n-1){
            dis = a[i+1] - a[i];
            //cout << (cnt-dis)/n << endl;
            if((cnt - dis) % n != 0 || cnt - dis < 0){
                puts("NO");
                return 0;
            }
            counter -= (cnt - dis) / n;
        }
        if(counter == 0) puts("YES");
        else puts("NO");
        //cout << cnt << counter << endl;
    }
}

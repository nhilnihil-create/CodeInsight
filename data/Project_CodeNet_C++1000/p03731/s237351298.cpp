#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

int main() {
    int n,t;
    cin >> n >> t;
    vector<int> vec(n);
    REP(i,n){
        cin >> vec.at(i);
    }
    int ans = t+vec.at(n-1)-vec.at(0);
    REP(i,n-1){
        ans -= max(0,vec.at(i+1)-vec.at(i)-t);
    }
    cout << ans << endl;
}
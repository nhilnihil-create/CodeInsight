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
    int n,m;
    cin >> n >> m;
    vector<int> vec(n); 
    REP(i,m){
        int a,b;
        cin >> a >> b;
        vec.at(a-1) += 1;
        vec.at(b-1) += 1;
    }
    REP(i,n){
        cout << vec.at(i) << endl;
    }
}
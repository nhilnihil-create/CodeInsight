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
    int a,b,c,x;
    cin >> a >> b >> c;
    x = (a-c)%b;
    FOR(i,1,10000){
        x = (x+a)%b;
        if (x==0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
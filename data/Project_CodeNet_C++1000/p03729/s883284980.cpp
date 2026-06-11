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
    string a,b,c;
    cin >> a >> b >> c;
    int A=a.size(),B=b.size();
    if (a.at(A-1)==b.at(0) && b.at(B-1)==c.at(0)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
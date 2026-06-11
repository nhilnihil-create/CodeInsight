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
    vector<int>vec = {0,1,3,1,2,1,2,1,1,2,1,2,1};
    int x,y;
    cin >> x >> y;
    if (vec.at(x) == vec.at(y)){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
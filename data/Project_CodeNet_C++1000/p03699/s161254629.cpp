#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    ll sum=0;
    REP(i, n){
        cin >> a.at(i);
        sum += a.at(i);
    }
    sort(ALL(a));
    REP(i, n){
        ll tmp=sum;
        FOR(j, i, n){
            if(tmp%10!=0){
                cout << tmp << endl;
                return 0;
            }
            tmp = sum-a[j]; 
        }
        sum -= a[i];    
    }
    
    cout << sum << endl;
}
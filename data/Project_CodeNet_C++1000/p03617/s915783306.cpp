#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!


ll min(ll a, ll b){return a<b?a:b;}

ll _find(ll one,ll two,ll N){
    if(N&1){
        return one + _find(one,two,N-1);
    }
    return min(N*one,N/2 * two);
}
void solve(){
    ll a,b,one,two;
    cin>>a>>b>>one>>two;
    
    b=min(b,2*a);
    one=min(one,2*b);
    
    ll N;
    cin>>N;
    
    cout<<_find(one,two,N);
    
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}
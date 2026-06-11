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

ll _find(ll a,ll b,ll c){
    vll arr={a,b,c};
    sort(all(arr));
    a=arr[0];
    b=arr[1];
    c=arr[2];
    
    if(a%2==0 || b%2==0 || c%2==0){
        return 0;
    }
    return a*b;
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<_find(a,b,c)<<endl;
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
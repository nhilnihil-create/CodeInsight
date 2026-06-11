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

// 1 way is to find compute all the sorted permutations and find the 
// positions of the current permutation.

int _find(ll a,ll b){
    if(a<=0 && b>=0){
        return 0;
    }
    // a,b
    if(a>0){
        return 1;
    }
    
    return (b-a+1)%2==0 ? 1:-1;
    
}

void solve(){
    ll a,b;
    cin>>a>>b;
    int ans=_find(a,b);
    if(ans>0){
        cout<<"Positive\n";
    }
    else if(ans==0){
        cout<<"Zero\n";
    }
    else{
        cout<<"Negative\n";
    }
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
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()0
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!

int n,k;
int xCordOf[105];

int distA(int y){
    return 2*abs(xCordOf[y]);
}
int distB(int y){
    return 2*abs(xCordOf[y]-k);
}
void solve(){
    cin>>n;
    cin>>k;
    for(int y=0;y<n;y++){
        int x;
        cin>>x;
        xCordOf[y]=x;
    }
    int sum=0;
    for(int y=0;y<n;y++){
        int d=min(distA(y),distB(y));
        if(d==INT_MAX){d=0;}
        sum+=d;
    }
    cout<<sum<<"\n";
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
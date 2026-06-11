#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define crap ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define assign(x,val) memset(x,val,sizeof(x))
const ll mod=1e9+7;
void solve(){
    int w,a,b;cin>>w>>a>>b;
    int x,y;
    x=min(a,b);
    y=max(a,b);
    if(x+w>=y){
    cout<<0;return;}
    cout<<y-(x+w);
}
int main() {
    crap;
	int t=1;
	//cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
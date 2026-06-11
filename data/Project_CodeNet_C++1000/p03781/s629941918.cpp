#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
void solve(){
    ll x;cin>>x;
    int i;
    for(i=1;;i++){
        if(i*(i+1)>=2*x)
        break;
    }
    cout<<i;
}
int  main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
    //cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
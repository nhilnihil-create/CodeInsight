#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b-a==c-b) cout<<"YES";
    else
    cout<<"NO";
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
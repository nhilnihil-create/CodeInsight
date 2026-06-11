#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
void solve(){
    string o,e;
    cin>>o;
    cin>>e;
    for(int i=0;i<min(o.length(),e.length());i++){
        cout<<o[i]<<e[i];
    }
    if(o.length()>e.length()) cout<<o[o.length()-1];
    else if(e.length()>o.length())
    cout<<e[e.length()-1];
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
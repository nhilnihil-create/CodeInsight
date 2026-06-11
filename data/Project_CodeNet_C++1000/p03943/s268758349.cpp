#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e6+6;
void solve(){
	int a[3];
	for(int i=0;i<3;i++)cin>>a[i];
	sort(a,a+3);
	if(a[0]+a[1]==a[2])cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}

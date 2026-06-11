#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
bool gray,brown,green,cyan,blue,yellow,orange,red;
int other;
int n;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		if(a<400) gray=1;
		else if(a<800) brown=1;
		else if(a<1200) green=1;
		else if(a<1600) cyan=1;
		else if(a<2000) blue=1;
		else if(a<2400) yellow=1;
		else if(a<2800) orange=1;
		else if(a<3200) red=1;
		else other++;
	}
	int ans=gray+brown+green+cyan+blue+yellow+orange+red;
	if(!ans) cout<<1<<' '<<other;
	else cout<<ans<<' '<<ans+other;
	re 0;
}

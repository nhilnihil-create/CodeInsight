#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n;
int sum,mn=1e5;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		sum+=a;
		if(a%10) mn=min(mn,a);
	}
	if(!sum){
		cout<<sum;
		re 0;
	}
	if(sum%10==0){
		sum-=mn;
		if(mn==1e5){
			cout<<0;
			re 0;
		}
	}
	cout<<sum;
	re 0;
}
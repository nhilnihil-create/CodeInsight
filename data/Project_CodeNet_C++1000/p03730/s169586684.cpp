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
int a,b,c;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>c;
	for(int i=1;i<=1e6;i++){
		if((b*i+c)%a==0){
			cout<<"YES";
			re 0;
		}
	}
	cout<<"NO";
	re 0;
}
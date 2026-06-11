#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,a,b=0,c=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a;
		if(a%2==0){
			b++;
		}else{
			c++;
		}
	}
	if(c%2==0){
		if(b>=1 &&c>=2){
			cout<<"YES"<<endl;
		}else if(b==0 && c>=2){
			cout<<"YES"<<endl;
		}else if(b>=1 && c==0){
			cout<<"YES"<<endl;
		}
	}else{
		if((b==1 && c==0) || (b==0&&c==1)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

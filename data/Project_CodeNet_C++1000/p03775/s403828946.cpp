#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	ll n; cin>>n;
	int mx=0;
	for(int i=1; i<=sqrt(n); i++){
		if(n%i==0){
			string sa=to_string(i);
			string sb=to_string(n/i);
			int ka=sa.size();
			int kb=sb.size();
			mx=max(ka,kb);
		}
	}
	cout<<mx<<endl;
}
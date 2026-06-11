#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,a,b,sum=0,bb=1;
	string s;
	cin>>n>>a>>b>>s;
	for(ll i=0;i<n;i++){
		if(s.substr(i,1)=="a"){
			if(sum<a+b){
				cout<<"Yes"<<endl;
				sum++;
			}else{
				cout<<"No"<<endl;
			}
		}else if(s.substr(i,1)=="b"){
			if(sum<a+b && bb<=b){
				cout<<"Yes"<<endl;
				sum++;
				bb++;
			}else{
				cout<<"No"<<endl;
			}
		}else if(s.substr(i,1)=="c"){
			cout<<"No"<<endl;

		}
	}
	return 0;
}

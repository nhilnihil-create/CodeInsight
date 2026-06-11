#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

vector<bool>a;

int main() {
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		if(s[i]==t[i]){
			a.push_back(0);
		}
		else{
			a.push_back(1);
			i++;
		}
	}
	ll ans=0;
	bool flag;
	if(a[0]==0){
		ans=3;
		flag=0;
	}
	else{
		ans=6;
		flag=1;
	}
	for(int i=1;i<a.size();i++){
		if(flag==0){
			if(a[i]==1){
				ans*=2;
				flag=1;
				continue;
			}
			else{
				flag=0;
				ans*=2;
				ans%=inf;
				continue;
			}
		}
		if(flag==1){
			if(a[i]==1){
				flag=1;
				ans*=3;
				ans%=inf;
				continue;
			}
			else{
				flag=0;
				ans*=1;
				continue;
			}
		}
	}
	cout <<ans;
	return 0;
}
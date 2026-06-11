#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

vector<ll> a, b;
int main() {
	ll n;
	string s,t;
	cin>>n>>s>>t;
	for(int i=0;i<s.size();i++){
		if(s[i]==t[i]){
			a.push_back(1);
		}
		else{
			a.push_back(2);
			i++;
		}
	}
	if(a[0]==1){
		b.push_back(3);
	}
	else{
		b.push_back(6);
	}
	for(int i=1;i<a.size();i++){
		if(a[i]==1){
			if(a[i-1]==1){
				b.push_back(2);
			}
			else{
				b.push_back(1);
			}
		}
		else{
			if(a[i-1]==1){
				b.push_back(2);
			}
			else{
				b.push_back(3);
			}
		}
	}
	ll ans=1;
	for(int i=0;i<b.size();i++){
		ans*=b[i];
		ans%=inf;
	}
	cout <<ans;
    // your code goes here
	return 0;
}
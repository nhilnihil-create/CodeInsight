#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	string s;cin>>s;
	int a[26]={};
	rep(i,26) a[s[i]-'a']++;
	int l=s.size();
	int ans=inf;
	rep(i,26){
		char c=i+'a';
		int sum=0,now=0;
		for(int j=0;j<l;j++){
			if(c==s[j]){
				sum=max(sum,j-now);
				now=j+1;
			}
		}
		sum=max(sum,l-now);
		ans=min(ans,sum);
	}

	cout<<ans<<"\n";
}
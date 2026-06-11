#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll ans;
ll pre[200005][26];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	for(int i=s.size()-1;i>=0;i--){
		int c=s[i]-'a';
		for(int j=0;j<26;j++){
			pre[i][j]=pre[i+1][j];
		}
		pre[i][c]++;
	}
	ans=s.size();ans*=(s.size()+1);ans/=2;
	ans+=1;
	for(int i=0;i<s.size();i++){
		ans-=pre[i][s[i]-'a'];
	}
	cout<<ans;
	return 0;
}
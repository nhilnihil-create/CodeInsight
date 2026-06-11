#include<bits/stdc++.h>
using namespace std;
int n,ans,sum;
string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='I')ans++;
		if(s[i]=='D')ans--;
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
}
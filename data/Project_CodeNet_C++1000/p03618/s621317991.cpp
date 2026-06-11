#include<bits/stdc++.h>
using namespace std;

int cnt[26];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	long long int ans=1;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<26;j++)
			if((s[i]-'a')!=j)
				ans+=cnt[j];
		cnt[s[i]-'a']++;
	}
	cout<<ans<<endl;
}

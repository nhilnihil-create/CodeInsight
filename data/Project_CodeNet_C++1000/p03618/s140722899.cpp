#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	vector<int> cnt(26);
	ll ans =0;
	for(auto c:s)
	{
		for(int i =0 ;i<26;i++)
		{
			if(i+'a'==c)continue;
			ans+=cnt[i];
		}
		cnt[c-'a']++;
	}
	cout<<ans+1<<endl;
}
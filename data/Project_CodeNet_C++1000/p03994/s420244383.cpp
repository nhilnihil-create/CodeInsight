#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	string s;
	cin >> s;
	int k ;
	cin >> k;
	int n = s.size();
	for(int i=0;i<n;i++)
	{
		if(('z'+1-s[i])%26<=k)
		{
			k -= ('z'+1-s[i])%26;
			s[i]='a';
			
		}
	}
	//cout<<k<<endl;
	s.back() = 'a'+(s.back()-'a'+k)%26;
	cout<<s<<endl;
	return 0;
}
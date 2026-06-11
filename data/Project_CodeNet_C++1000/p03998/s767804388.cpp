#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	int n[3];
	for(int i = 0;i<3;i++)n[i]= s[i].size();
	int now = 0;
	int m[3] = {};
	while(1)
	{

		if(m[now]==n[now])
		{
			cout<<(char)('A'+now)<<endl;
			return 0;
		}
		int next = s[now][m[now]]-'a';
		m[now]++;
		
		now = next;
		
	}
}

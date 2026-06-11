#include<bits/stdc++.h>
#define sc scanf
typedef long long ll;
using namespace std;
int flag[3];
int main()
{
	string s[3];
	for(int i=0;i<3;i++)
	{
		cin>>s[i];
		//s[i]+=(i+'A');
	}
	int cnt=0;
	while(1)
	{
		if(s[cnt].size()==0)
		{
			cout<<char(cnt+'A')<<"\n";
			break; 
		}
		int tmp=s[cnt][0];
		s[cnt].erase(0,1);
		cnt=tmp-'a';	
	}
	return 0;
}

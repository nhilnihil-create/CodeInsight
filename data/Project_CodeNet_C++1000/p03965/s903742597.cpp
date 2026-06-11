#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define debug(x) cout<<x<<"\n";
#define Max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f;
using namespace std;
int main()
{	
	string s;
	cin>>s;
	int p=0,g=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='g')
		g++;
		if(s[i]=='p')
		p++;
	}
	int r=(s.size()+1)/2,len=s.size();
	int ans=min(len-r,g);
	ans-=min(p,r);
	cout<<ans<<"\n";
	return 0;
} 
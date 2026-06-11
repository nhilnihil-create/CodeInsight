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
	char flag=s[0];
	int cnt=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!=flag)
		{
			cnt++;
			flag=s[i];
		}
	}
	cout<<cnt<<"\n";
	return 0;
} 
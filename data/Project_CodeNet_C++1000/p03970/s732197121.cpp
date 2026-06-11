#include <iostream>
#include <cstring>
using namespace std;
char s1[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
int cnt;
char s2[16];
int main()
{
	cin>>s2;
	for(int i=0;i<16;i++)
	{
		if(s1[i]!=s2[i])
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
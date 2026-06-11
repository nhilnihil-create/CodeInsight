#include<iostream>
#include<iomanip>
using namespace std;
char db[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
int main()
{
	char sr[16];
	int s=0;
	cin>>sr;
	for(int i=0;i<16;i++)
	{
		if(sr[i]!=db[i])
			s++;
	}
	cout<<s<<endl;
}
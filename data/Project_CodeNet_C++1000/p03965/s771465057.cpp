#include<bits/stdc++.h>
using namespace std;
string s;
int g=0,p;
int main()
{
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;++i)
		if(s[i]=='g')
			g++;
	p=len-g;
	cout<<min(len/2,g)-min(len/2,p)<<endl;
	return 0;
}
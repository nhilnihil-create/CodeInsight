#include<bits/stdc++.h>
using namespace std;
string s;
inline int read()
{
	int n_d=0,o_d=1;
	char c_d=getchar();
	while(c_d<'0'||c_d>'9')
	{
		if(c_d=='-')
			o_d=-1;
		c_d=getchar();
	}
	while(c_d>='0'&&c_d<='9')
	{
		n_d=n_d*10+c_d-'0';
		c_d=getchar();
	}
	return n_d*o_d;
}
int main()
{
    cin>>s;
   	int len=s.size();
    bool(s[0]==s[len-1])?(bool(len%2)?cout<<"Second\n":cout << "First\n"):(bool(len%2)?cout << "First\n":cout << "Second\n");
	return 0;
}

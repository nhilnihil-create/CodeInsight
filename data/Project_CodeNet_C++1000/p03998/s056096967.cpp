#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

int i[256];
int main()
{
	map<char,string>a;
	cin>>a['a']>>a['b']>>a['c'];
	
	char c='a',p;
	while(1)
	{
		if(a[c].size()==i[c]){cout<<(char)toupper(c)<<endl;return 0;}
		p=a[c][i[c]];
		i[c]++;
		c=p;
		
	
	}
	
}


#include <bits/stdc++.h>
using namespace std;
string x,y;
int main()
{
	cin>>x;
	y=x;
	reverse(y.begin(),y.end());
	for(int i=0;i<x.size();i++)
		switch(x[i])
		{
			case 'b':{x[i]='d';break;}
			case 'd':{x[i]='b';break;}
			case 'p':{x[i]='q';break;}
			default: x[i]='p';
		}
	if(x==y) cout<<"Yes";
	else cout<<"No";
    return 0;
}
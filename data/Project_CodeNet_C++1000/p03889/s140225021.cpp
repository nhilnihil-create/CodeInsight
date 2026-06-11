#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a;
	b=a;
	reverse(a.begin(),a.end());
	int len=a.length();
	for(int i=0;i<len;++i)
	{
		switch(a[i])
		{
           	case 'q': a[i]='p';break;
         	case 'p': a[i]='q';break;
       	    case 'b': a[i]='d';break;
            case 'd': a[i]='b';break;
		}
	}
	if(b==a)
		cout<<"Yes";
	else
		cout<<"No";
	cout<<endl;
	return 0;
}
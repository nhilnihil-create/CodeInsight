#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		switch(a[i])
		{
			case '0':b+='0';break;
			case '1':b+='1';break;
			case 'B':
				{
					if(b.size()>0)
					{
						string c;
						for(int i=0;i<b.size()-1;i++)
						{
							c+=b[i];
						}
						b=c;
					}
					break;
				}
		}
	}
	cout<<b;
}
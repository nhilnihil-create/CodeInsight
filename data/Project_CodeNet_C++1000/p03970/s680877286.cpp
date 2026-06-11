#include <bits/stdc++.h>
using namespace std;
int ans,b[16]={67,79,68,69,70,69,83,84,73,86,65,76,50,48,49,54};//CODEFESTIVAL2016的ASCII码值 
char a[16]; 
int main()
{
	for(int i=0;i<16;i++)
	{
		cin>>a[i];
		if(a[i]!=b[i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;	
}

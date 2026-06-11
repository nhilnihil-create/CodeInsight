#include<iostream>
#include<cstring>
using namespace std;

char a[20],b[]={"CODEFESTIVAL2016"};
int ans;

int main()
{
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++) if(a[i]!=b[i]) ans++;
	cout<<ans<<endl;
	return 0;
}
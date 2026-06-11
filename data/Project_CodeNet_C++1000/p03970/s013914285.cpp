#include<bits/stdc++.h>
using namespace std;
char a[20],mb[20]={"CODEFESTIVAL2016"};
int main() 
{
	int ans=0;
	scanf("%s",a);
	for (int i=0;i<16;i++)
	  if (a[i]!=mb[i]) ans++;
	printf("%d\n",ans);
	return 0;
}
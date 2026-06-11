#include<bits/stdc++.h>
#define l strlen(a)
using namespace std;
char a[100000];int x;
int main()
{
	scanf("%s",&a);x=abs(a[0]-a[l-1]);
	if(l%2==1){cout<<"No\n";return 0;}
	for(int i=0;i<l/2;i++,x=abs(a[i]-a[l-i-1]))
	  if(x!=1&&x!=2){cout<<"No\n";return 0;}
	cout<<"Yes\n";
	return 0;
}
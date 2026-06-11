#include <iostream>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int n,mn=1e9,mx=0,cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==mn)
			++cnt;
		if(a[i]<mn)
		{
			mn=a[i];
			cnt=1;
		}
		if(a[i]>mx)
			mx=a[i];
	}
	if(mx==mn)
	{
		if(a[1]==n-1)
			puts("Yes");
		else if(a[1]<=n/2)
			puts("Yes");
		else puts("No");
		return 0;
	}
	if(mx-mn>=2)
		puts("No");
	else if((n-cnt)/2+cnt<mx||cnt+1>mx)
		puts("No");
	else puts("Yes");
	return 0;
}
//dlstxdy!
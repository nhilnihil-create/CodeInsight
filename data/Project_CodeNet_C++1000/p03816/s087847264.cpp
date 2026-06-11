#include <bits/stdc++.h>
#define re register int
using namespace std;

int n,tmp,cnt;
bool a[100001];

int main()
{
	std::cin>>n;
	
	for(re i=1;i<=n;i++)
	{
		std::cin>>tmp;
		if(!a[tmp])
			a[tmp]=1;
		else
			cnt++;
	}
	
	if(cnt%2==1)
		cnt++;
	cnt=n-cnt;

	std::cout<<cnt;
	return 0;
}

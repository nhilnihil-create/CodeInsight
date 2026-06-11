#include <bits/stdc++.h>
#define re register int
using namespace std;

long long n,a,b,ans,x[100001];

int main()
{
	std::cin>>n>>a>>b;
	
	for(re i=1;i<=n;i++)
		std::cin>>x[i];
		
	for(re i=1;i<n;i++)
		ans+=std::min(a*(x[i+1]-x[i]),b);

	std::cout<<ans;
	return 0;
}

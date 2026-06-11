#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,b,c,d;
    scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
    for(int i=0;i<=n-1;i++)
        if((b-a)>=(i*c-(n-i-1)*d)&&(b-a)<=(i*d-(n-i-1)*c))
		{
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;    
}
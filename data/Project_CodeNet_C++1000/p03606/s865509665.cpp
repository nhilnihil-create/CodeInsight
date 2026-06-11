#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
long long n,a,b,sum;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a,&b);
        sum+=(b-a+1);
    }
	cout<<sum<<endl;
    return 0;
}
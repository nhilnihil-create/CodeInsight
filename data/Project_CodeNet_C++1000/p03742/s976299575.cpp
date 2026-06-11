#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main()
{
	scanf("%lld%lld",&a,&b);
	if(a>b)
		swap(a,b);
	printf("%s",b-a<=1?"Brown":"Alice");
}
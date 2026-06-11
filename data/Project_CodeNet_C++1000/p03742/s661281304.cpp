#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
#define LL long long
LL a,b;
int main()
{
	scanf("%lld%lld",&a,&b);
	printf("%s",((a-b)<2&&(a-b)>-2)?"Brown":"Alice");
}
#include<bits/stdc++.h> 
using namespace std;
typedef long long llong;
llong a,b,c;
llong f(llong x){
	if(x>=0) return x;
	else return -x;
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a%2==0||b%2==0||c%2==0){
		printf("%lld",0);
	}
	else {
		llong a1=a/2,a2=a-a1;
		llong s1=a1*b*c, s2=a2*b*c;
		llong b1=b/2,b2=b-b1;
		llong s3=a*b1*c, s4=a*b2*c;
		llong c1=c/2,c2=c-c1;
		llong s5=a*b*c1, s6=a*b*c2;
		llong ans1 = f(s1-s2),ans2=f(s3-s4),ans3=f(s5-s6);
		cout<<min(min(ans1,ans2),ans3);
	}
	return 0;
} 
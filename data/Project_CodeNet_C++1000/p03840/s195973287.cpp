#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
ll ans;
int a[8];
int main()
{
	for(int i=1;i<=7;++i)scanf("%d",&a[i]);
	ans+=a[2];ans+=2*(a[1]>>1);ans+=2*(a[4]>>1);ans+=2*(a[5]>>1);
	if((a[1]&1)&&(a[4]&1)&&(a[5]&1))ans+=3;
	else if((a[1]&1)&&(a[4]&1)&&(!(a[5]&1))&&a[5])ans+=1;
	else if((a[1]&1)&&(!(a[4]&1))&&(a[5]&1)&&a[4])ans+=1;
	else if((!(a[1]&1))&&(a[4]&1)&&(a[5]&1)&&a[1])ans+=1;
	cout<<ans<<endl;
	return 0;
}

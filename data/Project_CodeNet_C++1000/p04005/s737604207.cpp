#include<iostream>
#include<algorithm>
using namespace std;
//思路，两个小长方体组成一个大长方体，这两个长方体绝对是只能有一个数字不同，即ABC中只有一个不同
//而且每次都是取最小的对半分 
 
int main(void)
{
	long long int a[3];
	for(int i=0;i<3;i++)
		cin>>a[i];
	sort(a,a+3);		//升序
	long long int cut1=a[2]/2;
	long long int cut2=a[2]-cut1;
	cout<<a[0]*a[1]*(cut2-cut1)<<endl;
	return 0;
} 
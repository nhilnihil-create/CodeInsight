#include<iostream>
#include<algorithm>
using namespace std;
int k,a[109],l,m=0;
int main()
{
	cin>>l>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a[i];
		m+=a[i];
	}
	sort(a,a+k);
	m-=a[k-1];
	m=a[k-1]-m-1;
	if(m>0)
		cout<<m;
	else
		cout<<0;
	cout<<endl;
	return 0;
} 
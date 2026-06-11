#include<iostream>
#include<cstring>
using namespace std;
char a[]={"CODEFESTIVAL2016"},b[20];
int main()
{
	int sum=0;
	for(int i=0;i<16;i++)
	{
		cin>>b[i];
		if(b[i]!=a[i])
			sum++;
	}
	cout<<sum;
	return 0;
}
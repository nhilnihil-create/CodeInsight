#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	int mod = c % a;

	int sum = 0;
	for (int i = 0; i < a; i++)
	{
		sum = i * b;
		sum%=a;
		if ((mod + sum) % a == 0){cout<<"YES"<<endl; return 0;}
	}
	cout<<"NO"<<endl;


return 0;
}

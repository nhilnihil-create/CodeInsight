#include<bits/stdc++.h>
using namespace std;
int reem(int a,int b)
{
	if((a+b)<24)

	{
		return a+b;
	}
	else
		return ((a+b)-24);
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int a,b;
	cin>> a>>b;
	cout<<reem(a,b)<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if (a<=0 && b>=0) return cout<<"Zero",0;
	b=min(b,-1);
	if (a>b || (b-a+1)%2==0) return cout<<"Positive",0;
	cout<<"Negative";
}

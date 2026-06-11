#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n>0)
	{
		if(n%10==9)
		{
			cout<<"Yes"<<endl;
			break;	
		}
		if(n%10!=9&&n/10==0)
		{
			cout<<"No"<<endl;
			break;
		}
		n=n/10;
	}
	return 0;
}

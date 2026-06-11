#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll a,b;
	cin>>a>>b;
	if(b>0&&a>0) cout<<"Positive"<<endl;
	else if(b<0)
	{
		if((b-a+1)%2==0) cout<<"Positive"<<endl;
		else cout<<"Negative"<<endl;
	}
	else
	{
		cout<<"Zero"<<endl;
	}
	return 0;
}

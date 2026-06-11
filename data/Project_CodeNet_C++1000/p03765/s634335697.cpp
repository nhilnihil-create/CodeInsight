#include<bits/stdc++.h>
using namespace std;

int tongS[100001]={0},tongT[100001]={0},q;
string S,T;

int main()
{
	cin>>S>>T;
	S=' '+S;
	T=' '+T;
	
	for(int i=1;i<S.length();++i)
	{
		tongS[i]=(tongS[i-1]+(S[i]-64));
	}
	
	for(int i=1;i<T.length();++i)
	{
		tongT[i]=(tongT[i-1]+(T[i]-64));
	}
	cin>>q;
	
	int x,y,z,t;
	for(int i=1;i<=q;++i)
	{
		cin>>x>>y>>z>>t;
		if((tongS[y]-tongS[x-1])%3==(tongT[t]-tongT[z-1])%3)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}

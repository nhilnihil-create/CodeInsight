#include <iostream>
#include <string>
using namespace std;
long long a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
string S1,S2="CODEFESTIVAL2016";
int main()
{
	cin>>S1;
	for(i=0;i<S1.size();i++)
	{
		if(S1[i]!=S2[i])
		z++;
	}
	cout<<z<<endl;
	return 0;
}
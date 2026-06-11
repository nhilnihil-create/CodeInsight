#include <bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,i,j=0,k,m=1,n=1;
cin>>i;
while(i--)
{
	cin>>a>>b;
	j=max((m+a-1)/a,(n+b-1)/b);
	m=a*j, n=b*j;
}
cout<<m+n<<endl;
return 0;
}

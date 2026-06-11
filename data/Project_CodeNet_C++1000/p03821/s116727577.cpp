#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i,j,k,a,n,c=0;
	cin>>n;
	long long A[n],B[n];
	for(i=0;i<n;i++)
	cin>>A[i]>>B[i];
  	for(i=n-1;i>=0;i--)
		{
       if((A[i]+c)%B[i]==0) continue;
			 c+=B[i]-(A[i]+c)%B[i];
		}
		cout<<c<<endl;
}

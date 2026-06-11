#include<bits/stdc++.h>
using  namespace  std;

#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define nl      '\n'

typedef long long int ll;
typedef unsigned long long int  llu;


int main()
{
	faster;
	int n,i,sum=0;
	cin>>n;
	int l=2*n;
	int a[l+1];
	for(i=0;i<l;i++)cin>>a[i];
	sort(a,a+l);
	for(i=0;i<l;i+=2)sum+=a[i];
	cout<<sum<<nl;
	return 0;
}

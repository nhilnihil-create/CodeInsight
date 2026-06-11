#include <bits/stdc++.h>
#define li long long int
using namespace std;

int main() {
	li n,sum=0;
	cin>>n;
	n=2*n;
	li a[n],i;
	for(i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	
	for(i=0;i<n-1;i=i+2){
	    li aa,b;
	    aa=a[i];
	    b=a[i+1];
	    sum+=min(aa,b);
	}
	cout<<sum<<endl;
	return 0;
}

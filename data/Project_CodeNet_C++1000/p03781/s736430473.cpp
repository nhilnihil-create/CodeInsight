#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ll i,j,k,l,n;
	cin>>n;
	i=1; j=1e10;
	ll mid,an=0;
	while(j>=i){
		mid=(i+j)/2;
		
		k=(mid*(mid+1))/2;
		if(k>=n){
			an=mid;
			j=mid-1;
		}
		else i=mid+1;
	}
	cout<<an;
	return 0;
}
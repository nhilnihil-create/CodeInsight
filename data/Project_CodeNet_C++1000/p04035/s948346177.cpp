#include<bits/stdc++.h>
using namespace std;
int n,k,a[100003];
int main(){cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	int mxm=0,j=-1;
	for(int i=1;i<n;i++)
		if(a[i-1]+a[i]>mxm){
			mxm=a[i-1]+a[i];
			j=i;
		}
	if(mxm<k)
		cout<<"Impossible";
	else{
		cout<<"Possible";
		for(int i=1;i<j;i++)
			cout<<endl<<i;
		for(int i=n-1;i>=j;i--)
			cout<<endl<<i;
	}
}
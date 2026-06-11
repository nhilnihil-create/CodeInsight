#include<bits/stdc++.h>
using namespace std;

int a[200000],b[200000],n;

bool check(int m){
	for(int i=0;i<2*n-1;i++)
		b[i]=(a[i]>=m);
	for(int i=0;i<2*n-2;i++){
		if(b[i]==b[i+1])	continue;
		int j=i+1;
		while(j+1<2*n-1&&b[j+1]!=b[j])	j++;
		if((j-i)&1){
			for(int k=i+1;k<=i+(j-i)/2;k++)
				b[k]=b[i];
			for(int k=i+(j-i)/2+1;k<j;k++)
				b[k]=b[j];
		}
		else{
			for(int k=i+1;k<j;k++)
				b[k]=b[i];
		}
		i=j;
	}
	return b[n-1]==1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<2*n-1;i++)
		cin>>a[i];
	int l=1,r=2*n-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
}

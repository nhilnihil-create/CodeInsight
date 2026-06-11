#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int n,a[N<<1];

bool can(int u){
	for(int i=0;i<n-1;i++){
		if(a[n+i]<=u&&a[n+i+1]<=u){
			return true;
		}
		if(a[n-i]<=u&&a[n-i-1]<=u){
			return true;
		}
		if(a[n+i]>u&&a[n+i+1]>u){
			return false;
		}
		if(a[n-i]>u&&a[n-i-1]>u){
			return false;
		}
	}
	return a[1]<=u;
}

int bs(int l,int r){
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if(can(mid)){
		return bs(l,mid);
	}
	else{
		return bs(mid+1,r);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<(n<<1);i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",bs(1,(n<<1)-1));
	return 0;
}
#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define N 500009
#define inf 999999999999
#define pb push_back
#define M (L+R)/2
using namespace std;

ll n,a[N],b[N],c[N];

bool check(ll x){

	for(int i=1;i<2*n;i++){
		if(a[i]<x)c[i]=0;
		else c[i]=1;
	}

	ll left=0,right=0;
	int j=n;
	while(j>1 && c[j]!=c[j-1]){
		j--;
		left++;
	}
	j=n;
	while(j<2*n-1 && c[j]!=c[j+1]){
		j++;
		right++;
	}	

	if(left>right)left=right;
	if(left%2==0){
		if(c[n]==1)return true;
		else return false;
	} else {
		if(c[n]==1)return false;
		else return true;
	}
}

int main(){

	ios::sync_with_stdio(0);

	cin>>n;
	for(int i=1;i<2*n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	
	sort(b+1,b+2*n);
	
	ll L=1,R=2*n-1,pas=0;
	
	while(L<=R){
		
		if(check(M)){
			pas=M;
			L=M+1;
		} else {
			R=M-1;
		}
		
	}
	
	cout<<pas<<endl;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[200100];
int n;
bool check(int mid){
	if(a[n+1]<=mid&&a[n]<=mid||a[n]<=mid&&a[n-1]<=mid)
		return 1;
	if(a[n+1]> mid&&a[n]> mid||a[n]> mid&&a[n-1]> mid)
		return 0;
	for(int i=1;i<n-1;i++){
		if(a[n+i+1]<=mid&&a[n+i]<=mid||a[n-i]<=mid&&a[n-i-1]<=mid)
			return 1;
		if(a[n+i+1]> mid&&a[n+i]> mid||a[n-i]> mid&&a[n-i-1]> mid)
			return 0;
	}
	return a[1]<=mid;
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=2*n-1;i++){
		cin>>a[i];
	}
	int le=0;
	int ri=2*n-1;
	while(le!=ri){
		int mi=(le+ri)/2;
		if(check(mi))
			ri=mi;
		else
			le=mi+1;
	}
	cout<<le<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
int a[200100];
bool b[200100];
bool check(int mid){
	for(int i=1;i<=2*n-1;i++)
		b[i]=(a[i]<=mid);
	for(int i=0;i<n-1;i++){
		if(b[n-i]==1&&b[n-i-1]==1||b[n+i]==1&&b[n+i+1]==1)
			return 1;
		if(b[n-i]==0&&b[n-i-1]==0||b[n+i]==0&&b[n+i+1]==0)
			return 0;
	}
	return b[1];
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=2*n-1;i++)
		cin>>a[i];
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

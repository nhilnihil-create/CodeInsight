#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1666666
#define inf 9999999999999
int n;
int arr[N];
signed main(){
	cin>>n;
	for(int i=1;i<=2*n;i++) cin>>arr[i];sort(arr+1,arr+1+2*n);
	int ans=inf;int l=1;int s=0;
	for(int i=1;i<=2*n;i++) if(i%2) s+=arr[i];
	cout<<s;
    return 0; 
}
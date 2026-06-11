#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1666666
#define inf 9999999999999
int n;
int arr[N];
int f(int a,int b){
	if(b%a==0){
		return (2*(b/a)-1)*(a);
	}else{
		return ((2*a)*(b/a))+f(b%a,a);
	}
}
signed main(){
	int n,x;
	cin>>n>>x;
	int ans=n;
	ans+=f(x,n-x);
	cout<<ans;
    return 0; 
}
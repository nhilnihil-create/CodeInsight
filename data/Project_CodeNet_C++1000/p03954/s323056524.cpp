/*************************************************************************
	> File Name: AT2165.cpp
	> Author: s-k-y
	> Mail: zhoutianyi0330@qq.com 
	> Created Time: 2019年11月07日 星期四 08时54分07秒
 ************************************************************************/

#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define F(i,a,b) for(register long long i=a;i<=b;i++)
#define K(i,a,b) for(register long long i=a;i>=b;i--)
using namespace std;
ll a[1000001],n,f[1000001],t,k,l,r,o;
ll pd(ll x){
	t=0;
	if(a[1]>x)f[1]=1;
	else f[1]=0;
	o=f[1];
	F(i,2,n*2-1){
		if(a[i]>x)f[i]=1;
		else f[i]=0;
		if(t==0){
			if(f[i]==f[i-1]){
				t=i;
				o=f[i];
			}
		}
		else if(f[i]==f[i-1]&&abs(n-i+1)<abs(n-t+1)){
			t=i;
			o=f[i];
		}
	}
	return o;
}
int main(){
	cin>>n;
	F(i,1,n*2-1)cin>>a[i];
	l=1;r=n*2-1;
	while(l<r){
		ll mid=(l+r)>>1;
		if(pd(mid)==0){
			r=mid;
		}
		else l=mid+1;
	}
	cout<<r;
	return 0;
}
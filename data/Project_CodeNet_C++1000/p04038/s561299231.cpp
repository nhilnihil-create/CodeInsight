#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const long long mod=1000000007;
int n,k;
long long fac[5000003],inv[5000003],ifac[5000003],d[2003][2003];
inline long long C(long long n,long long m){
	if(n<m){
		return 0;
	}
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	cin>>n>>k;
	if(k==1){
		cout<<1<<endl;
		return 0;
	}
	fac[0]=inv[0]=ifac[0]=fac[1]=inv[1]=ifac[1]=1;
	for(int i=2;i<=5000000;i++){
		fac[i]=(fac[i-1]*i)%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		ifac[i]=(ifac[i-1]*inv[i])%mod;
	}
	d[0][1]=1;
	for(int i=2;i<=n;i++){
		d[0][i]=d[0][i-1]*C(i*(k-1)-1,k-2)%mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			d[i][j]=(d[i-1][j]+d[i][j-1]*C(i+j*(k-1)-1,k-2)%mod)%mod;
		}
	}
	cout<<(d[n][n]*fac[n])%mod<<endl;
	return 0;
}
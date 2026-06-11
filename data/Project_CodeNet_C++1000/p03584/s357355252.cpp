#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int a[100000],b[100000];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	rep(i,n)scanf("%d%d",&a[i],&b[i]);
	ll Max=0;
	rep(i,n){
		if((k|a[i])==k)Max+=b[i];
	}
	rep(i,30){
		if(!(k>>i&1))continue;
		ll sum=0;
		int c=(k^(1<<i))|((1<<i)-1);
		rep(j,n){
			if((c|a[j])==c)sum+=b[j];
		}
		Max=max(Max,sum);
	}
	cout<<Max<<endl;
}
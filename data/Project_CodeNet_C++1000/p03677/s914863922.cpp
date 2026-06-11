#include<bits/stdc++.h>
#define M 100005
#define L long long
using namespace std;
L n,last,m;
L a[M]={0},pls[M]={0},jump[M]={0};
L unless=0,now=0,maxn=0;
int main(){
	scanf("%lld%lld%lld",&n,&m,&last);
	for(L i=2;i<=n;i++){
		L x; scanf("%lld",&x);
		if(x>=last){
			jump[last+1]++; jump[x+1]--; 
			a[last]++,a[x]--,pls[x+1]+=x-last,unless+=x-last;
		}
		else{
			jump[last+1]++; jump[m+1]--;
			jump[1]++; jump[x+1]--;
			a[last]++; a[m]--; pls[m+1]+=m-last;
			a[1]++; a[x]--; pls[1]-=m-last+1; pls[x+1]+=(m-last+x);
			unless+=m-(last-x);maxn=max(maxn,now);
		}
		last=x;
	}
	for(L i=1;i<=m;i++){
		now=now-pls[i];
		now-=jump[i];
		maxn=max(maxn,now);
		a[i]+=a[i-1];
		now+=a[i];
	}
	cout<<unless-maxn<<endl;
}
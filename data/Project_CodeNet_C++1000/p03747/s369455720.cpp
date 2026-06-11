#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int n,l,t,x[100005],w[100005];
ll ans;
int main(){
	scanf("%d%d%d",&n,&l,&t);
	for(int i=1;i<=n;++i)scanf("%d%d",x+i,w+i);
	for(int i=1;i<=n;++i){
		if(w[i]==1){
			ans+=(x[i]+t)/l;
			(x[i]+=t)%=l;
		}
		else{
			ans+=(x[i]-t)/l;
			(x[i]-=t)%=l;
			if(x[i]<0)x[i]+=l,--ans;
		}
	}
	ans=(ans%n+n)%n+1;
	sort(x+1,x+n+1);
	for(int i=ans;i<=n;++i)printf("%d\n",x[i]);
	for(int i=1;i<ans;++i)printf("%d\n",x[i]);
	return 0;
}
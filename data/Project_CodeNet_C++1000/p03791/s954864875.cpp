#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

int x[200000];
int need(int n){
	return n*2-1;
}
int main(){
	int n;scanf("%d",&n);
	rep(i,n)scanf("%d",&x[i]);
	ll ans=1;
	int s=-1;
	rep(i,n){
		while(need(s+2-i)<=x[s+1])s++;
		if(need(s+1-i)+1<=x[s+1])s++;
		(ans*=(s+1-i))%=MOD;
	}
	cout<<ans<<endl;
}

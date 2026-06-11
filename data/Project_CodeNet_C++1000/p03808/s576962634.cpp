#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll arr[100005];
ll pre[100005];
ll total,moves;

int main(){
	//freopen("input.txt","r",stdin);
	
	scanf("%lld",&n);
	for (int x=0;x<n;x++) scanf("%lld",&arr[x]);
	for (int x=0;x<n;x++) total+=arr[x];
	moves=n*(n+1)/2;
	
	if (total%moves){
		printf("NO\n");
		return 0;
	}
	moves=total/moves;
	
	
	pre[0]=arr[0]-arr[n-1];
	for (int x=1;x<n;x++){
		pre[x]=arr[x]-arr[x-1];
	}

	for (int x=0;x<n;x++){
		pre[x]=moves-pre[x];
		if (pre[x]%n || pre[x]/n>moves || 0>pre[x]){
			printf("NO\n");
			return 0;
		}
		
	}
	printf("YES\n");
}

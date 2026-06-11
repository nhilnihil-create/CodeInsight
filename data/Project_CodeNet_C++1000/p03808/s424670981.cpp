#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5;

int n;
int li[N+5];

inline LL itung(LL x){
	return ((1LL+x)*x)/2;
}

int main(){
	scanf("%d",&n);
	LL tot = 0LL;
	int idm = 1e9+7;
	int idM = -1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&li[i]);
		tot+=li[i];
		idm = min(idm,li[i]);
		idM = max(idM,li[i]);
	}
	LL bisa = itung(n);
	if(tot%bisa != 0){
		printf("NO\n");
		return 0;
	}
	int l = -1;
	int r = -1;
	int tmp = n;
	for(int i=1;i<=n;i++){
		if(idm == li[i]){
			l = i;
		}
		if(idM == li[i]){
			r = i;
			if(l!=-1)tmp = min(tmp,r-l+1);
		}
	}
	for(int i=1;i<=n;i++){
		if(idM == li[i]){
			if(l!=-1) tmp = min(tmp,n-(r-l-1));
		}
	}
	sort(li+1,li+n+1);
	if(li[1]*(LL)(tmp) < li[n]){
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	return 0;
}

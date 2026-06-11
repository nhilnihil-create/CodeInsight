#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)

using namespace std;

const int N=1e5+10;
int n,a[N],o,e;

bool solve(){
	if (!e) return 0;
	if (e&1) return 1;
	if (o!=1) return 0;
	else{
		int g=0;
		rep (i,1,n)
			if (a[i]!=1){
				if (a[i]&1) a[i]--;
				g=__gcd(g,a[i]);
			}
		e=o=0;
		rep (i,1,n)
			if (a[i]!=1){
				a[i]/=g;
				if (a[i]!=1) o+=a[i]&1,e+=!(a[i]&1);
			}
		return solve()^1;
	}
}

int main(){
	scanf("%d",&n);
	rep (i,1,n){
		scanf("%d",&a[i]);
		if (a[i]!=1) o+=a[i]&1,e+=!(a[i]&1);
	}
	puts(solve()?"First":"Second");
	return 0;
}
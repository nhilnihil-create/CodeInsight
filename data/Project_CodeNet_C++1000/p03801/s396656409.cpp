#include<bits/stdc++.h>
#define filename "task name"
#define fi first
#define se second
using namespace std;
const int N = 1e5+5 ;
const int mod = 1e9+7 ;
#define int long long
int n,m,t,ans[N] ;
pair<int , long long> a[N] ; 
void fre(){
	if (fopen(filename".INP", "r")) {
   	   	freopen(filename".INP", "r", stdin);
   		freopen(filename".OUT", "w", stdout);
   	}
}
main(){
	fre();
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i].fi;
		a[i].se=i; 
	}
	sort(a+1,a+n+1) ;
	a[0].fi = 0 ; 
	a[0].se = 0 ;
	int j=n, idx=a[n].se; 
	while(j>0) {
		int i ; 
		for(i = j ; i > 0 && a[i].fi == a[j].fi ; i-- ) {
			idx = min(idx,a[i].se) ;  
		}
		int cnt = n-i ; 
		ans[idx] += cnt*(a[i+1].fi-a[i].fi) ;
		j = i ; 
	} 
	for(int i=1; i<=n; i++) cout << ans[i] << endl ; 
}

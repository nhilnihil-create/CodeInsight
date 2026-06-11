#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod ((ll)(1e9)+7)

int main(){
	int n;
	cin >> n;
	vector<ll> t(n+2), a(n+2);
	for(int i=1; i<=n; i++) cin >> t[i];
	for(int i=1; i<=n; i++) cin >> a[i];
	t[0]=0;
	a[n+1]=0;

	ll ans=1;
	for(int i=1; i<=n; i++){
		if(t[i]==t[i-1] && a[i]==a[i+1]){
			ans=ans*min(t[i], a[i])%mod;
		}else if(t[i]>t[i-1] && a[i]==a[i+1]){
			if(t[i]>a[i]) ans=0;
		}else if(t[i]==t[i-1] && a[i]>a[i+1]){
			if(a[i]>t[i]) ans=0;
		}else{
			if(t[i]!=a[i]) ans=0;
		}
	}
	cout << ans << endl;
	return 0;
}
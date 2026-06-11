#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0);
#define ll long long
#define int ll
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define all(n) (n).begin(),(n).end()
using namespace std;
signed main(){
	IOS;
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	int dif = abs(a-b);
	n -- ;
	int l = c * n , r = d * n;
	
	bool ok = 0;
	for(int i = 0;i < n;i++){
		if(dif>=l && dif <=r) ok =1;
		l -= c+d , r -= c+d;
	}
	cout<<(ok?"YES\n":"NO\n");
	
}

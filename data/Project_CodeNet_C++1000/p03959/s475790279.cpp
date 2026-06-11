#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int mi[114514],ma[114514];
signed main(){
	int n;
	cin>>n;
	vector<int> tak(n), aok(n);
	for(int i=0;i<n;i++){
		cin>>tak[i];
	}
	for(int i=0;i<n;i++){
		cin>>aok[i];
	}
	for(int i=0;i<n;i++){
		mi[i] = 1;
		ma[i] = inf;
	}
	for(int i=0;i<n;i++){
		if( i == 0 || tak[i-1] < tak[i] ){
			mi[i] = max( mi[i], tak[i] );
			ma[i] = min( ma[i], tak[i] );
		}
		else{
			ma[i] = min(ma[i], tak[i]);
		}
	}
	for(int i=n-1;i>=0;i--){
		if( i == n-1 || aok[i+1] < aok[i] ){
			mi[i] = max( mi[i], aok[i] );
			ma[i] = min( ma[i], aok[i] );
		}
		else{
			ma[i] = min( ma[i] , aok[i]);
		}
	}
	int ans = 1;
	for(int i=0;i<n;i++){
		//cout<<mi[i]<<" "<<ma[i]<<endl;
		ans *= max( 0LL, ma[i]-mi[i]+1);
		ans %= inf;
	}
	cout<<ans<<endl;
	return 0;
}
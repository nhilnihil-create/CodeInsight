#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 1000000000000000007LL
#define ll long long
using namespace std;
int cnt[114514];
int amari[114514];
int msp[114514];
signed main(){
	int n,m;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
		cnt[x]++;
	}
	for(int i=1;i<=100000;i++){
		amari[i%m] += cnt[i];
	}
	for(int i=1;i<=100000;i++){
		msp[i%m] += cnt[i]/2;
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		if( i == 0 || m == 2 * i){
			ans += amari[i]/2;
			amari[i] %= 2;
		}
		else{
			int cp = min( amari[i], amari[m-i] );
			ans += cp;
			amari[i] -= cp;
			amari[m-i] -= cp;
		}
	}
	for(int i=0;i<m;i++){
		ans += min( msp[i], amari[i]/2 );
	}
	cout<<ans<<endl;
	return 0;
}
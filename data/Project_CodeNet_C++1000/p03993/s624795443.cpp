/*
	The Island Was Silent before.
	.....
	And One day again it became Silent.
*/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll  long long
#define modd(a,b) ((a+2*b)%b)
#define debug(a) cout << #a << ": " << (a) << "\n"
#define ioso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rtt cerr << "Time: " << clock()*1.0 / CLOCKS_PER_SEC << endl;
#define ffe freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);

int main() {
	#ifndef ONLINE_JUDGE
	//ioso ffe
	#endif
	int t; cin >> t;
	int a[100010];
	for(int cas=1;cas<=t;cas++) {
		//cout << " : " << cas << ": ";
		cin >> a[cas];

	}
	ll cnt=0;
	for(int i=1;i<=t;i++) {
		if(a[a[i]]==i) {cnt++; a[a[i]]=0; a[i]=0;}
	}
	cout << cnt << endl;
}
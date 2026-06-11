#include<bits/stdc++.h>
using namespace std;

#define  vt            vector
#define  db            long double
#define  int           long long
#define  pb            push_back
#define  inf           (int)1e20
#define  mxn           (int)2e5+5
#define  pii           pair<int,int>
#define  pq            priority_queue

#define  si(x)         (int)x.size()
#define  all(x)        x.begin(),x.end()
#define  mem(a,x)      memset(a,x,sizeof(a))
#define  forr(i,n)     for(int i=0;i<n;i++)

#define deb(x)   cout<<"> "<<#x<<" : "<<x<<endl
#define pnr(a)   for(auto x:a){cout<<x<<" ";}cout<<endl;
#define pnr2(a)  for(auto x:a){cout<<x.first<<" "<<x.second<<endl;}

int mainx()
{
	int n , k , x , y;
	cin >> n >> k >> x >> y;
	int ans = 0;
	if (n <= k)
		ans = x * n;
	else
	{
		ans = k * x + (n - k) * y;
	}
	cout << ans << endl;
	return 0;
}


inline void include() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
}
int32_t main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//cout << fixed << setprecision(20);

	int tt = 1;
	//cin>>tt;
	for (int t = 1 ; t <= tt ; t++ )
	{
		mainx();
	}
	return 0 ;
}

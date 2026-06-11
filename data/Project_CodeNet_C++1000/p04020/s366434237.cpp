#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define trace(x)     cerr<<#x<<":"<<x<<endl;
#define trace2(x,y) cerr<<#x<<":"<<x<<"|"<<#y<<":"<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<":"<<x<<"|"<<#y<<":"<<y<<"|"<<#z<<":"<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main() {
	fast_io;
	ll n;
	cin >> n;
	vl a(n + 1);
	ll ans = 0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for (int i = 1; i <= n; i++) {
		ll csum = 0;
		if(a[i]>0){
			for(int j=i;j<=n;j++){
				if(a[j] == 0){
					break;
				}
				csum += a[j];
				i++;
			}
		}
		ans = ans + (csum/2);
	}
	
	cout << ans;
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}
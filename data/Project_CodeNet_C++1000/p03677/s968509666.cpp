#include <bits/stdc++.h>
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w
using namespace std;

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,m,a[100000],mi,dec[100000] = {},add[100000] = {},ans = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];a[i]--;
		if(i){
			ans += min((a[i] + m - a[i - 1]) % m,1 + a[i] % m);
			dec[a[i - 1] + 1]++;
			dec[a[i] + 1]--;
			add[a[i] + 1] += (a[i] + m - a[i - 1]) % m;
			if(a[i] < a[i - 1]) dec[0]++;
		}
	}
	for(int i = 1;i < m;i++) dec[i] += dec[i - 1];
	mi = ans;
	for(int i = 1;i < m;i++){
		ans -= dec[i - 1];
		ans += add[i];
		mi = min(mi,ans);
	}
	cout << mi << endl;
	return 0;
}
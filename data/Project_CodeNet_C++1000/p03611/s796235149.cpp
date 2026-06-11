#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 1e5+5;
int n, x, maks=-1;
unordered_map<int, int>arr;

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		arr[x+1]++;
		arr[x]++;
		arr[x-1]++;
		maks=max(maks, x+1);
	}
	int ans=-1;
	for(int i=0;i<=maks;i++){
		ans=max(ans, arr[i]);
	}	
	cout << ans << '\n';
}

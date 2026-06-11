#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll n, arr[105], ans=0;
vector<ll>v;
	
int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		ans+=arr[i];
		if(arr[i]%10!=0){
			v.pb(arr[i]);
		}
	}
	if(ans%10!=0){
		cout << ans << '\n';
		return 0;
	}
	else{
		if(v.empty()){
			cout << 0 << '\n';
			return 0;
		}
		sort(v.begin(), v.end());
		if(v[0]>ans) cout << 0 << '\n';
		else cout << ans-v[0] << '\n';
	}
}

#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 1e5 + 5;
ll n, sums=0, m;

int main(){
	IOS
	cin >> n;
	int arr[n+5];
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		sums+=arr[i];
	}
	cin >> m;
	while(m--){
		int a, b;
		ll temp=sums;
		cin >> a >> b;
		ll jarak=b-arr[a];
		temp+=jarak;
		cout << temp << '\n';
	}
}

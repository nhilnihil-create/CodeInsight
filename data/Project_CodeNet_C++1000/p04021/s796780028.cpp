#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pbb pair<bool,bool>
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define xmod (ll)(1e9+7) 
#define hmod 1286031825167LL
using namespace std;

int n,a[100005],b[100005],ans;
map <int,int> m;
int main(){	
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;i++){
    	cin >> a[i];
    	b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++){
		m[b[i]]=i;
	}
	for (int i=1;i<=n;i++){
		if (i%2 != m[a[i]]%2)
		ans++;
	}
	cout << ans/2 << "\n";
    return 0;
}	
//1 2 3 4
//2 4 3 1
//4 1 3 2
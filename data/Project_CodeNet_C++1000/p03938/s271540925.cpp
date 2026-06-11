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

int n,x,p[20005];
int main(){	
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i=1;i<=n;i++){
    	cin >> x;
    	p[x]=i;
	}
	for (int i=1;i<=n;i++){
		cout << i*50000 << " ";
	}
	cout << "\n";
	for (int i=1;i<=n;i++){
		cout << (n-i)*50000+p[i] << " ";
	}
	cout << "\n";
    return 0;
}	
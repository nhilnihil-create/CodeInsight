#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n], b[n];
	set<int> s;
	rep(i,0,n){
		cin >> a[i];	
		b[i] = a[i];
	}
	sort(b,b+n);
	rep(i,0,n){
		if(i&1){
			s.insert(b[i]);
		}
	}
	int ans = 0;
	rep(i,0,n){
		if(i % 2 == 0){
			ans += s.count(a[i]);
		}
	}
	cout << ans << '\n';
}

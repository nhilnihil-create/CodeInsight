#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int n, m; 
int a[200]; 
bool v[2000000]; 
bool v2[2000000]; 

int main() {
	cin>>n>>m; 
	for (int i = 1; i <= m; ++i) scanf( "%d", &a[i] ); 
	int l = 0; 
	for (int i = 1; i <= m; ++i) l += a[i]/2; 
	if (l + n/2 < n-1) {
		printf( "Impossible\n" ); 
		return 0; 
	}
	for (int i = 2; i <= m; ++i) 
		if (a[i] % 2 == 1) swap(a[1], a[i]); 
	for (int i = 2; i < m; ++i) 
		if (a[i] % 2 == 1) swap(a[i], a[m]);  
	for (int i = 1; i <= m; ++i) printf( "%d ", a[i] ); 
	puts( "" ); 
	if (a[1] % 2 == 1) {
		if (m == 1) {
			if (a[1] == 1) printf( "1\n1" ); 
			else printf( "2\n%d %d", 1, a[m]-1 ); 
		}
		else {
			vi ans; 
			ans.pb( a[1]+1 ); 
			for (int i = 2; i < m; ++i) ans.pb(a[i]); 
			if (a[m] > 1) ans.pb(a[m]-1); 
			cout<<ans.size()<<endl; 
			for (auto i : ans) printf( "%d ", i ); 
			puts( "" ); 
		}
	}
	else {
		printf( "%d\n", m+1 ); 
		printf( "1 "); 
		for (int i = 1; i < m; ++i) printf( "%d ", a[i] ); 
		printf( "%d ", a[m]-1);
	}
	puts( "" ); 
}

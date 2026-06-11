#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 4;
int n;
pair<int, int> a[MAXN];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0;i < n;i ++)
		cin >> a[i].first, a[i].second = i;
	sort(a, a + n);
	int ans = 0;
	for( int i = 0; i < n; i ++){
		if( (a[i].second % 2) != (i % 2))
			ans ++;
	}
	cout << ans/2 << endl;
	return 0;
}

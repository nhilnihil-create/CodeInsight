#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int n, a[MAXN];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a, a + n, greater< int >());
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if( a[i] <= cnt) break;
		cnt ++;
	}
	int x = 0;
	for(int i = cnt; i < n; i ++)
		if( a[i] >= cnt) x ++;
		
	if( x % 2 || (a[cnt - 1] - cnt) % 2 )
		cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}


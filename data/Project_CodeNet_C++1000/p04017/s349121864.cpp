#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 100;
const int lg = 17;
int x[N],d[N][lg + 1];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,L;
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> x[i];
	cin >> L;
	for(int i = n;i >= 1;--i){
	    d[i][0] = ((upper_bound(x + 1,x + 1 + n, x[i] + L)) - x - 1);
	    for(int j = 1;j <= lg;++j){
	        d[i][j] = d[d[i][j - 1]][j - 1];
	    }
	}
	int q;
	cin >> q;
	while(q--){
	    int a,b;
	    cin >> a >> b;
	    if(a == b){
	        cout << 0 << '\n';
	        continue;
	    }
	    if(a > b)swap(a, b);
	    int ans = 1;
	    for(int i = lg;i >= 0;--i){
	        if(d[a][i] < b){
	            a = d[a][i];
	            ans += (1 << i);
	        }
	    }
	    cout << ans << '\n';
	}
	
  	return 0;
} 
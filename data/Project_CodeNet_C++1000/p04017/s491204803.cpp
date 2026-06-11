#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define ins insert
#define er erase

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

const int oo = 1e18 + 7, mod = 1e9 + 7;

int n, x[100005], L, q;
int sparse[100005][17];

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	cin >> L;
	x[n + 1] = oo;
	for(int i = 1; i < n; i++){
	    int l = i + 2, r = n + 1;
	    while(l != r){
	        int mid = (l + r) >> 1;
	        if((x[mid] - x[i]) <= L) l = mid + 1;
	        else r = mid;
	    }
	    l--;
	    sparse[i][0] = l;
	    //cout << i << " " << 0 << " " << sparse[i][0] << "\n";
	}
	for(int i = 1; i <= 16; i++){
	    for(int j = 1; j <= n; j++){
	        sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
	        if(!sparse[j][i]) sparse[j][i] = n;
	        //cout << i << " " << j << " " << sparse[j][i] << "\n";
	    }
	}
	cin >> q;
	while(q--){
	    int a, b, ans = 0;
	    cin >> a >> b;
	    if(a > b) swap(a, b);
	    for(int i = 16; i >= 0; i--){
	        if(sparse[a][i] < b){
	            ans += (1 << i);
	            a = sparse[a][i];
	        }
	    }
	    ans++;
	    cout << ans << "\n";
	}
}


#include <bits/stdc++.h>
#define vi  vector<int>
#define ii  pair<int,int>
#define x   first
#define y   second
#define all(x)  (x).begin(),(x).end()
using namespace std;
int logn = 1;
ii query(int cur, int dest, vector<vector<ii>> &stick){
    int sum = 0;
    for(int i = logn-1;i>=0;--i){
        if(dest - cur >= (1<<i)){
            sum += stick[cur][i].x;
            cur = stick[cur][i].y;
        }
    }
    return {sum, cur};
}

int32_t main() {
	int n,l, q; cin >> n;
	for(int i = n-1;i;i/=2) ++logn;
	vi arr(n);
	vector<vector<ii>> stick(n,vector<ii>(logn));
	for(auto &v:arr) cin >> v;
	cin >> l >> q;
	for(int i=0;i<n;i++){
	    stick[i][0] = {1, upper_bound(all(arr), arr[i] + l) - arr.begin() - 1};
	}
	for(int j=1;j<logn;j++){
	    for(int i=0;i<n;i++){
	        int tar = i+(1<<j);
	        if(tar > n-1) continue;
	        ii res = query(stick[i][0].y, tar, stick);
	        stick[i][j] = {stick[i][0].x + res.x, res.y};
	    }
	}
	for(int a,b;q--;){
	    cin >> a >> b; --a, --b;
	    if(b < a) swap(a,b);
	    cout << query(a,b,stick).x <<'\n';
	}
	cout <<endl;
	return 0;
}

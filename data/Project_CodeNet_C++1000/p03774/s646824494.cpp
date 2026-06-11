
// Problem : B - Checkpoints
// Contest : AtCoder - AtCoder Beginner Contest 057
// URL : https://atcoder.jp/contests/abc057/tasks/abc057_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define spc ' '
#define endl '\n'

using namespace std;


int main(){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m, x, y, c, mx, d;
	cin >> n >> m;
	vector<pair<int,int>> st(n), ch(m);
	vector<int> ans(n);
	for(int i = 0; i < n; i++){
	    cin >> x >> y;
	    st[i] = make_pair(x,y);
	}
	for(int i = 0; i < m; i++){
	    cin >> x >> y;
	    ch[i] = make_pair(x,y);
	}
	for(int i = 0; i < n; i++){
	    mx = INT_MAX;
	    for(int j = 0; j<m; j++){
	        d = abs(st[i].first - ch[j].first) + abs(st[i].second- ch[j].second);
	        if(mx > d){
	            ans[i] = j+1;
	            mx = d;
	        }
	    }
	}
	for(int answer:ans){
	    cout << answer<< endl;
	}
	return 0;
}
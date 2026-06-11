#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,k;
	cin >> n >> k;
	priority_queue<int> q;
	rep(i,n){
		int l;
		cin >> l;
		q.push(l);
	}
	int ans = 0;
	rep(i,k){
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
}
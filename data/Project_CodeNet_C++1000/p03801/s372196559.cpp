#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

int n, a[100005], ind[100005], mxpref[100005], suffix[100005];
ii srt[100005];
stack<int> stk;

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		srt[i] = {a[i], i};
	}
	sort(srt + 1, srt + n + 1);
	for(int i = 1; i <= n; i++) ind[srt[i].se] = i;
	for(int i = n; i >= 0; i--) suffix[i] = (suffix[i + 1] + srt[i].fi); 
	for(int i = 1; i <= n; i++) mxpref[i] = max(mxpref[i - 1], ind[i]);
	int tol = 0;
	for(int i = n; i >= 1; i--){
		if(ind[i] < mxpref[i - 1]){
			stk.push(0);
			continue;
		}
		stk.push(suffix[mxpref[i - 1]] - srt[mxpref[i - 1]].fi * (n - mxpref[i - 1] + 1) - tol);
		tol += stk.top();
	}
	while(!stk.empty()){
		cout << stk.top() << "\n";
		stk.pop();
	}
}

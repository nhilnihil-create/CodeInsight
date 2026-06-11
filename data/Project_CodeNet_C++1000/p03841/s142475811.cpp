#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 500 + 5;

int ans[N*N], cnt[N];

vector<pii> ord;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	rep(i,1,n+1){
		int x;
		cin >> x;
		ord.push_back({x,i});
		ans[x] = i;
	}
	sort(all(ord));
	queue<int> q, lft;
	for(pii p:ord){
		rep(i,0,p.second-1)q.push(p.second);
	}
	bool val = 1;
	rep(i,1,n*n+1){
		if(ans[i] == 0){
			if(q.size()){
				ans[i] = q.front();	
				++cnt[ans[i]];
				q.pop();
			}
			else if(lft.size()){
				ans[i] = lft.front();
				lft.pop();
			}
			else {
				val = false;
				break;
			}
		}
		else {
			rep(j,0,n-ans[i])lft.push(ans[i]);
			if(cnt[ans[i]] < ans[i] - 1){
				val = false;
				break;
			}
		}
	}
	if(val){
		cout << "Yes" << '\n';	
		rep(i,1,n*n+1)cout << ans[i] << ' ';
		cout << '\n';
	}
	else{
		cout << "No" << '\n';
	}
}

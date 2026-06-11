#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>
#include<time.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;


int n, m, k, c[101010], a[101010], d[101010], ans[101010];
vector<int> v[101010];
int finish[101010];

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> a[i] >> d[i] >> c[i];
	}
	
	for(int i = 0; i <= n; i++){
		finish[i] = -1;
	}
	for(int i = k-1; i >= 0; i--){
		queue<P> q;
		q.push(P(a[i], d[i]));
		while(!q.empty()){
			P p = q.front();
			q.pop();
			int pos = p.first, now = p.second;
			if(finish[pos] >= now) continue;
			finish[pos] = now;
			if(ans[pos] == 0) ans[pos] = c[i];
			for(int j = 0; j < v[pos].size(); j++){
				q.push(P(v[pos][j], now-1));
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}
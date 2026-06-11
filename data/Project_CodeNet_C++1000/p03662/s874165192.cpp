#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N;
	vector<vector<int> > edge;

	cin >> N;
	edge.resize(N+1);
	int a,b;
	for(int i = 0; i < N-1; i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	vector<bool> use(N+1,false);
	queue<int> f,s;
	f.push(1), s.push(N);
	use[1] = true, use[N] = true;
	int fmasu = 1, smasu = 1;
	for(int i = 0; f.size() || s.size(); i++){
		queue<int> next, check = i&1 ? s : f;
		while(check.size()){
			int now = check.front();
			check.pop();
			for(int j = 0; j < edge[now].size(); j++)
				if(!use[edge[now][j]])
					next.push(edge[now][j]), use[edge[now][j]] = true;
		}

		if(i&1)
			s = next, smasu += next.size();
		else
			f = next, fmasu += next.size();
	}
	// cerr << fmasu << " " << smasu << endl;

	if(fmasu > smasu)
		cout << "Fennec" << endl;
	else
		cout << "Snuke" << endl;

	return 0;
}
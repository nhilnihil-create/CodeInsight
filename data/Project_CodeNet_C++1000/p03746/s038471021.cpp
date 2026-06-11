#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
bool used[100001];
vector<vector<int>> e;

void extend_path(vector<int>& path){
	bool f = false;
	while(!f){
		f = true;
		int t = path.back();
		for(int i = 0; i < e[t].size(); i++){
			if(used[e[t][i]] == false){
				f = false;
				path.emplace_back(e[t][i]);
				used[e[t][i]] = true;
				break;
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	e = vector<vector<int>>(n + 1);
	vector<int> l, r, ans;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		e[a].emplace_back(b);
		e[b].emplace_back(a);
		if(i == 0){
			used[a] = true; used[b] = true;
			l.emplace_back(a);
			r.emplace_back(b);
		}
	}
	extend_path(l);
	extend_path(r);
	reverse(begin(l), end(l));
	ans = l;
	ans.insert(end(ans), begin(r), end(r));
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size() - 1; i++){
		cout << ans[i] << " ";
	}
	cout << ans.back() << endl;
	return 0;
}
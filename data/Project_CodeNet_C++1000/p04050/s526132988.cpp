#include<bits/stdc++.h>
using namespace std;

#define MAX 100002

int n;
int m;

vector<int> v;

vector<int> vv[2];
vector<int> w;

vector<int> ans;
int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a;
		scanf("%d", &a);
		vv[a&1].push_back(a);
		w.push_back(a);
	}
	if (m == 1 && w[0] == 1){
		cout << w[0] << endl;
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if (m == 1){
		cout << w[0] << endl;
		cout << 2 << endl;
		cout << w[0] - 1 <<" "<<1<< endl;
		return 0;
	}
	if (vv[1].size()>
		2){
		puts("Impossible");
		return 0;
	}
	if (vv[1].size()){
		vv[0].insert(0 + vv[0].begin(), vv[1].back());
		vv[1].pop_back();
	}
	if (vv[1].size()){
		vv[0].push_back(vv[1].back());
		vv[1].pop_back();
	}
	for (int i : vv[0]){
		ans.push_back(i);
	}
	ans[0]--;
	if (ans[0] == 0){
		ans.erase(ans.begin() + 0, ans.begin() + 1);
	}
	ans.back()++;
	for (int i = 0; i < vv[0].size(); i++){
		if (i){
			printf(" ");
		}
		printf("%d", vv[0][i]);
	}
	puts("");
	cout << ans.size()<< endl;
	for (int i = 0; i < ans.size(); i++){
		if (i){
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
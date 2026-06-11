#include<bits/stdc++.h>
using namespace std;

long long N;
vector<long long> tree[100005];

long long grundy(long long pa, long long cur){
	long long ret = 0;
	for(long long i = 0; i < tree[cur].size(); i++){
		if(tree[cur][i] != pa){
			ret = ret ^ grundy(cur, tree[cur][i]);
		}
	}
	if(cur == 0){
		//cout << "cur = " << cur << " ret = " << 0 << endl;
		return ret;
	}
	if(tree[cur].size() == 1){
		//cout << "cur = " << cur << " ret = " << 1 << endl;
		return 1;
	}
	return ret + 1;
}



int main(){
	cin >> N;
	for(long long i = 0; i < N - 1; i++){
		long long x, y;
		cin >> x >> y;
		x--;y--;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	if(grundy(-1, 0) == 0){
		cout << "Bob" << endl;
	}else{
		cout << "Alice" << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

inline void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	int n, m;
	cin >> n >> m;
	vector<int> st, ed;
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		if(a == 1)
			st.push_back(b);
		if(b == n)
			ed.push_back(a);
	}
	sort(ed.begin(), ed.end());
	for(auto num : st)
		if(binary_search(ed.begin(), ed.end(), num)){
			cout << "POSSIBLE";
			return 0;
		}
	cout << "IMPOSSIBLE";
	return 0;
}

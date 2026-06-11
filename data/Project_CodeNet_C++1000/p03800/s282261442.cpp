#include <bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int> ans(N);
	// 4ways to think
	// SS SW WS WW
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			vector<int> res;
			res.push_back(i);
			res.push_back(j);
			for(int k=0;k<N;k++){
				if(s[k]=='o')res.push_back(res[k]^res[k+1]);
				else res.push_back(res[k]^res[k+1]^1);
			}
			if(res[N] == i && res[N+1] == j){
				for(int l=1;l<=N;l++){
					cout << (res[l]? 'W': 'S');
				}
				cout << endl;
				return 0;
			}
		}
	}
	puts("-1");
}
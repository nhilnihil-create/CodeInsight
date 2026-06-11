#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> PII;

const int MAXN = 200000;
vector<int> group[MAXN];
int main() {
	int N,M;
	
	vector<int> input;
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		int x;
		cin >> x;
//		input.push_back(x);
		group[x%M].push_back(x);
	}
	for(int i=0; i<MAXN; i++)
		sort(group[i].begin(), group[i].end());
	vector<int> pair(MAXN, 0);
	
	for(int i=0; i<MAXN; i++) {
		bool flag = false;
		for(int j=0; j<group[i].size(); j++) {
			if(flag) {
				if(group[i][j] == group[i][j-1]) pair[i]++, flag = false;
				else flag = true;
			}
			else flag = true;
		}
		
	}
	
	int ans = 0;
	
	for(int i=0; i<=M/2; i++) {
		if( (i + i) % M == 0) {
			ans += group[i].size() - group[i].size() % 2 ;
			
			continue;
		}
		int p = group[i].size();
		int q = group[M-i].size();
		
		int score = min(p,q) * 2;;
		
		if(p>q) {
			if(p-q < 2 * pair[i]) score = p+q - (p+q)%2;
			else score += pair[i] * 2;
		}
		else {
			if(q-p < 2 * pair[M-i]) score = p+q - (p+q)%2;
			else score += pair[M-i] * 2;
		}
		ans += score;
//		cout << ans << endl;
	}
	//for(int i=0; i<M; i++) cout << pair[i] << endl;
	
	cout << ans / 2 << endl;
	return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair

int n, m;

vector <int> l[200000];
int bio[200000];
deque <int> Q; 

int dfs2 (int x) {
	bio[x] = 1;
	Q.push_front(x);
	for (int i=0; i<l[x].size(); i++) {
		if (bio[l[x][i]] == 0) {
			return dfs2(l[x][i]);
		}
 	}
}

int dfs1 (int x) {
	bio[x] = 1;
	Q.push_back(x);
	for (int i=0; i<l[x].size(); i++) {
		if (bio[l[x][i]] == 0) {
			return dfs1(l[x][i]);
		}
 	}
}

int main() {
	
	cin >>n >>m;
	
	for (int i=0; i<m; i++) {
		int a, b;
		cin >>a >>b;
		l[a].push_back(b);
		l[b].push_back(a);
	}
	
	dfs1(1);
	for (int i=0; i<l[1].size(); i++) {
		if (bio[l[1][i]] == 0) {
			dfs2(l[1][i]);
			break;
		}
	}
	cout <<Q.size() <<endl;
	while(!Q.empty()) {
		cout <<Q.front() <<" ";
		Q.pop_front();
	}
	
	return 0;
}

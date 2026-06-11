#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int N, M;
	cin >> N >> M;
	set<pair<int,int>> s;
	for(int i=0;i<M;i++) {
		int a, b;
		cin >> a >> b;
		s.insert({a,b});
	}
	for(int i=2;i<N;i++) {
		if(s.count({1,i})&&s.count({i,N})) {
			puts("POSSIBLE");return 0;
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}



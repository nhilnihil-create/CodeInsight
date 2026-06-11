#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, K;

void solve()
{
	for(int r=0;r<=N;++r)for(int c=0;c<=M;++c){
		int cnt = c*N+r*(M-c)-r*c;
		if(cnt == K){
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main()
{
	cin >> N >> M >> K;
	solve();
	return 0;
}
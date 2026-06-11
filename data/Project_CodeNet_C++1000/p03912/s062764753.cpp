#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
typedef long long ll;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> X(N), cnt(100001), md(M), dob(M);
	for(int i = 0; i < N; ++i){
		cin >> X[i];
		cnt[X[i]]++;
		md[X[i]%M]++;
	}
	for(int i = 1; i < 100001; ++i){
		dob[i%M] += cnt[i] / 2;
	}
	int res = md[0] / 2;
	if(M % 2 == 0){
		res += md[M / 2] / 2;
	}
	for(int i = 1; i <= M / 2; ++i){
		if(M % 2 == 0 && i == M / 2) continue;
		int u = i, v = M - i;
		if(md[u] > md[v]){
			swap(u,v);
		}
		int n = md[u];
		//cout << n << endl;
		res += n;
		res += min(md[v]-n, 2 * dob[v]) / 2;
	}
	cout << res << endl;
	return 0;
}

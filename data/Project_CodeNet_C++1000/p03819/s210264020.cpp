#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
pair< int, pair<int, int> > range[300005];

int bit[300005];

int query(int i)
{
	int ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= i & (-i);
	}
	return ret;
}

void add(int i, int val)
{
	while(i <= M+1){
		bit[i] += val;
		i += i & (-i);
	}
}

int main(void)
{
	cin >> N >> M;
	int l, r;
	for(int i = 0; i < N; i++){
		cin >> l >> r;
		range[i] = make_pair(r-l+1, make_pair(l, r));
	}
	sort(range, range+N);

	int p = 0;
	for(int i = 1; i <= M; i++){
		while(p < N && range[p].first < i){
			add(range[p].second.first, 1);
			add(range[p].second.second + 1, -1);
			p++;
		}
		int ans = 0;
		for(int j = i; j <= M; j+=i) ans += query(j);
		cout << ans + (N - p) << endl;
	}
	return 0;
}
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int N, K, L;
int road[200005], rail[200005];
pair<P, int> cmp[200005];
P tmp[200005];
int ans[200005];

void init(int parent[])
{
	for(int i = 1; i <= N; i++) parent[i] = i;
}

int root(int parent[], int i)
{
	if(parent[i] == i) return i;
	return parent[i] = root(parent, parent[i]);
}

void unite(int parent[], int i, int j)
{
	int root_i = root(parent, i);
	int root_j = root(parent, j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}

int main(void)
{
	cin >> N >> K >> L;
	init(road), init(rail);
	
	int p, q;
	for(int i = 0; i < K; i++){
		cin >> p >> q;
		unite(road, p, q);
	}
	for(int i = 0; i < L; i++){
		cin >> p >> q;
		unite(rail, p, q);
	}
	
	for(int i = 1; i <= N; i++) root(road, i), root(rail, i);
	for(int i = 1; i <= N; i++){
		cmp[i] = make_pair(make_pair(road[i], rail[i]), i);
	}
	sort(cmp+1, cmp+N+1);
	for(int i = 1; i <= N; i++) tmp[i] = cmp[i].first;
	
	int pos = 1, l, r;
	while(pos <= N){
		l = lower_bound(tmp+1, tmp+N+1, tmp[pos]) - tmp;
		r = upper_bound(tmp+1, tmp+N+1, tmp[pos]) - tmp;
		for(int i = l; i < r; i++) ans[cmp[i].second] = r - l;
		pos = r;
	}
	
	for(int i = 1; i <= N; i++){
		cout << ans[i];
		if(i != N) cout << " ";
	}
	cout << endl;
	return 0;
}
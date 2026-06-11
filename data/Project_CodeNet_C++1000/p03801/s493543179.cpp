#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
static const int MAX_N = 100000;

int N;
P p[MAX_N];
ll res[MAX_N];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &p[i].first);
		p[i].second = i;
	}
	sort(p, p + N);
	reverse(p, p + N);
	int min_index = MAX_N;
	for(int i = 0; i < N; i++){
		min_index = min(min_index, p[i].second);
		if(i == N - 1) res[min_index] += p[i].first * (ll)(i + 1);
		else res[min_index] += (p[i].first - p[i + 1].first) * (ll)(i + 1);
	}
	
	for(int i = 0; i < N; i++) printf("%lld\n", res[i]);
	return 0;
}
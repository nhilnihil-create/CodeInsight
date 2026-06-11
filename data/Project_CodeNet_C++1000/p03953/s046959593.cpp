#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll;

const int MAXN = 100010;

int seq[MAXN], num[MAXN], cnt;
vector<int> cir[MAXN];
ll a[MAXN], dif[MAXN];
int ans[MAXN];

inline void Swap(int& a, int& b){a ^= b ^= a ^= b;}

int main(){
	int N, M; ll K;
	scanf("%d", &N);
	for (int i = 1, tmp; i <= N; ++i)
		scanf("%lld", &a[i]), dif[i] = a[i] - a[i - 1], seq[i] = i;
	scanf("%d %lld", &M, &K);
	for (int i = 1, tmp; i <= M; ++i)
		scanf("%d", &tmp), Swap(seq[tmp], seq[tmp + 1]);
	for (int i = 1, j; i <= N; ++i)
		if (!num[i]){
			num[i] = ++cnt, j = seq[i];
			cir[cnt].push_back(i);
			while (j != i){
				num[j] = cnt, cir[cnt].push_back(j);
				j = seq[j];
			}
		}
	for (int i = 1, st, j, k; i <= cnt; ++i){
		st = cir[i][K % (ll) cir[i].size()];
		ans[cir[i][0]] = st;
		j = seq[st], k = 1;
		while (j != st){
			ans[cir[i][k]] = j;
			j = seq[j], ++k;
		}
	}
	ll sum = 0; 
	for (int i = 1; i <= N; ++i)
		sum += dif[ans[i]], printf("%lld\n", sum);
	return 0;
}
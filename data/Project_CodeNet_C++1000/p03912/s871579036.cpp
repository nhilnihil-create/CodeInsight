#include<cstdio>
#include<algorithm>

using namespace std;

const int MA = 100100;

int cnt[100100];
int M;

int calc(int r){
	if(r * 2 == M || r == 0){
		int all = 0;
		for(int i = r; i < MA; i += M){
			all += cnt[i];
		}
		return all / 2;
	}
	int l1 = 0, dif1 = 0;
	int all1 = 0;
	for(int i = r; i < MA; i += M){
		if(cnt[i] % 2 == 1) l1++;
		all1 += cnt[i];
		dif1 += cnt[i] / 2;
	}
	int l2 = 0, dif2 = 0;
	int all2 = 0;
	for(int i = (M - r); i < MA; i += M){
		if(cnt[i] % 2 == 1) l2++;
		all2 += cnt[i];
		dif2 += cnt[i] / 2;
	}
	int r1 = l1 + dif1 * 2;
	int r2 = l2 + dif2 * 2;
	int all = all1 + all2;
	if((all1 + all2) % 2 == 1){
		all--;
		if(l1 < l2){
			l2--;
			r2--;
		}else{
			l1--;
			r1--;
		}
	}
	if(r1 < l2){
		return (all - (l2 - r1)) / 2;
	}else if(r2 < l1){
		return (all - (l1 - r2)) / 2;
	}else{
		return all / 2;
	}
}

int solve(){
	int ans = 0;
	for(int i = 0; i * 2 <= M; ++i){
		ans += calc(i);
	}
	return ans;
}

void input(){
	int N;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
}

int main(){
	input();
	int ans = solve();
	printf("%d\n", ans);
	return 0;
}

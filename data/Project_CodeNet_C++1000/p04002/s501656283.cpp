#include <cstdio>
#include <set>
using namespace std;

long long int cnt[10];
set<pair<int, int> > s;

int main(){
	int H, W, N, a, b, t;
	scanf("%d %d %d", &H, &W, &N);
	cnt[0] = 1LL * (H-2) * (W-2);
	while(N--){
		scanf("%d %d", &a, &b);
		s.insert({a, b});
		for(int i=max(1, a-2); i<=min(H-2, a); ++i){
			for(int j=max(1, b-2); j<=min(W-2, b); ++j){
				t = 0;
				for(int y=i; y<i+3; ++y){
					for(int x=j; x<j+3; ++x){
						if(s.count({y, x}))
							++t;
					}
				}
				++cnt[t];
				--cnt[t-1];
			}
		}
	}
	for(int i=0; i<10; ++i)
		printf("%lld\n", cnt[i]);
}

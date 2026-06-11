#include <bits/stdc++.h>

using namespace std;

int i;
long long n;
deque <int> ans;

int main(){
	scanf("%lld", &n);
	
	n++;
	
	long long now = 1;
	int cnt = -1;
	
	while(now <= n){
		now *= 2;
		cnt++;
	}
	
	int nxt = 0;
	
	for(i = cnt - 1; i >= 0; i--){
		nxt++;
		ans.push_back(nxt);
		if(n & (1LL << i)){
			nxt++;
			ans.push_front(nxt);
		}
	}
	
	for(i = 1; i <= nxt; i++)
	ans.push_back(i);
	
	printf("%d\n", ans.size());
	
	for(i = 0; i < ans.size(); i++){
		if(i == 0)
		printf("%d", ans[i]);
		else
		printf(" %d", ans[i]);
	}
	
	printf("\n");
}

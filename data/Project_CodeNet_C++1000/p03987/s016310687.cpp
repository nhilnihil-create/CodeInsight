#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int N, a[MAXN];

int main(){
	scanf("%d", &N);
	
	stack < pair <int, int> > s;
	long long res = 0, cur = 0;
	
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
		
		int cnt = 1;
		while(!s.empty()){
			pair <int, int> t = s.top();
			if(t.first < a[i])break;
			
			s.pop();
			cur -= 1LL * t.first * t.second;
			cnt += t.second;
		}
		s.push(make_pair(a[i], cnt));
		cur += 1LL * a[i] * cnt;
		
		res += cur;
	}
	
	printf("%lld\n", res);
	
	return 0;
}

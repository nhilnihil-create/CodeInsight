#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

typedef long long ll;

ll n, m;
deque < int > q;

void yap(ll n){
	if(n == 1)
		return;
	if(n%2){
		yap(n - 1);
		q.push_back(++m);
	}else{
		yap(n/2);
		q.push_front(++m);
	}
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld",&n);
	yap(n + 1);
	printf("%lld\n", m+m);
	while(!q.empty()){
		printf("%d ", q.back());
		q.pop_back();
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", i);
	return 0;
}
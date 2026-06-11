#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

typedef long long ll;

const int N = 2e5 + 500;

int L[N], R[N], n, p[N];
stack < int > S;

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", p + i);
	for(int i = 0;i < n;i++){
		for(;!S.empty() && p[S.top()] > p[i];S.pop());
		if(S.empty())
			L[i] = 0;
		else
			L[i] = S.top() + 1;
		S.push(i);
	}
	for(;!S.empty();S.pop());
	for(int i = n - 1;i >= 0;i--){
		for(;!S.empty() && p[S.top()] > p[i];S.pop());
		if(S.empty())
			R[i] = n - 1;
		else
			R[i] = S.top() - 1;
		S.push(i);
	}
	ll sol = 0;
	for(int i = 0;i < n;i++){
		sol += (ll)(i - L[i] + 1) * (ll)(R[i] - i + 1) * (ll)p[i];
	}
	printf("%lld\n", sol);
}

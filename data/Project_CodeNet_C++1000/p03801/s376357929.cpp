#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[101010], B[101010], D[101010];
vector <ll> S;
ll n;

int main()
{
	ll i, j;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++){
		scanf("%lld", A + i);
		B[i] = A[i];
	}
	
	for(i=n; i>=1; i--){
		for(; !S.empty() && A[S.back()] <= A[i]; S.pop_back());
		S.push_back(i);
	}
	
	S.push_back(0);
	
	sort(B + 1, B + n + 1);
	
	for(i=0, j=n; i<S.size()-1; i++){
		D[S[i]] += (n - j) * (A[S[i]] - A[S[i + 1]]);
		for(; j>=1 && B[j]>A[S[i + 1]]; j--){
			D[S[i]] += (B[j] - A[S[i + 1]]);
		}
	}
	
	for(i=1; i<=n; i++){
		printf("%lld\n", D[i]);
	}
	
	return 0;
}
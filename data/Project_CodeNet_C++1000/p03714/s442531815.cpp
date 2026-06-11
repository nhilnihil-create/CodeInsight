#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
 
int N;
vector<ll> A(300001, 0);
priority_queue<ll, vector<ll>, greater<ll>> fque;
priority_queue<ll> bque;
ll fsum = 0, bsum = 0;
vector<ll> fv, bv;

int main(void){
	
	scanf("%d", &N);
	for(int i = 0; i < 3 * N; ++i) scanf("%lld", &A[i]);
	
	for(int i = 0; i < N; ++i) fque.push(A[i]), fsum += A[i];
	for(int i = 3 * N - 1; i >= 2 * N; --i) bque.push(A[i]), bsum += A[i];
	
	fv.push_back(fsum);
	for(int i = N; i < 2 * N; ++i){
	    fque.push(A[i]);
	    fsum += A[i];
	    fsum -= fque.top(); fque.pop();
	    fv.push_back(fsum);
	}
	
	bv.push_back(bsum);
	for(int i = 2 * N - 1; i >= N; --i){
	    bque.push(A[i]);
	    bsum += A[i];
	    bsum -= bque.top(); bque.pop();
	    bv.push_back(bsum);
	}
    reverse(bv.begin(), bv.end());
    
    ll ans = -LLONG_MAX;
    for(int i = 0; i < fv.size(); ++i) ans = max(ans, fv[i] - bv[i]);
    printf("%lld\n", ans);
    
    return 0;
}
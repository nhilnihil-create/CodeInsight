// D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rp(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main(){
	int N; cin>>N;
	vector<ll> A(3*N);
	rp(i, 3*N) cin>>A[i];

	vector<ll> F(3*N);
	F[0] = A[0];
	priority_queue<int> fque;
	fque.push(-A[0]);
	for(int i=1; i<3*N; ++i){
		fque.push(-A[i]);
		ll minA = 0;
		if(fque.size() > N){
			minA = -fque.top();
			fque.pop();
		}
		F[i] += F[i-1] + A[i] - minA;
	}

	reverse(all(A));

	vector<ll> B(3*N);
	B[0] = A[0];
	priority_queue<int> bque;
	bque.push(A[0]);
	for(int i=1; i<3*N; ++i){
		bque.push(A[i]);
		ll minA = 0;
		if(bque.size() > N){
			minA = bque.top();
			bque.pop();
		}
		B[i] += B[i-1] + A[i] - minA;
	}

	ll maxfb = LLONG_MIN;
	rp(i, N+1){
		int f = N - 1 + i;
		int b = 3*N - 1 - N - i;
		maxfb = max(maxfb, F[f]-B[b]);
	}
	cout<< maxfb <<endl;

}
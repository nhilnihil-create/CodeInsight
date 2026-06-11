// D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)
#define pq priority_queue

int main(){
	int N;
	cin>>N;
	int N2 = N*2;
	int N3 = N*3;
	VL A(N3);
	rp(a, 0, N3) cin>>A[a];

	VL F(N+1);
	pq<int> fque;
	rp(a, 0, N){
		fque.push(-A[a]);
		F[0] += A[a];
	}
	for(int a=N, f=0; f<N; ++f, ++a){
		fque.push(-A[a]);
		F[f+1] = F[f] + A[a] - (-fque.top());
		fque.pop();
	}

	VL B(N+1);
	pq<int> bque;
	irp(a, N3-1, N2-1){
		bque.push(A[a]);
		B[N] += A[a];
	}
	for(int a=N2-1, b=N; b>0; --b, --a){
		bque.push(A[a]);
		B[b-1] = B[b] + A[a] - (bque.top());
		bque.pop();
	}

	ll maxfb = LLONG_MIN;
	rp(i, 0, N+1) maxfb = max(maxfb, F[i]-B[i]);
	cout<< maxfb <<endl;
}
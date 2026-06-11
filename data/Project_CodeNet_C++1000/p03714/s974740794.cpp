// D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define pq priority_queue

#define NMAX 100000
int N;
VL A(3*NMAX);

void f(VL &V, ll sign){
	V[0] = A[0];
	pq<int> que;
	que.push(sign*A[0]);
	rp(i, 1, 3*N){
		que.push(sign*A[i]);
		ll topA = 0;
		if(que.size() > N){
			topA = sign*que.top();
			que.pop();
		}
		V[i] += V[i-1] + A[i] - topA;
	}
}

int main(){
	cin>>N;
	int N3 = N*3;
	rp(i, 0, N3) cin>>A[i];

	VL F(N3), B(N3);
	f(F, -1L);
	reverse(A.begin(), A.begin()+N3);
	f(B, 1L);

	ll maxfb = LLONG_MIN;
	rp(i, 0, N+1){
		int f = N - 1 + i;
		int b = N3 - 1 - N - i;
		maxfb = max(maxfb, F[f]-B[b]);
	}
	cout<< maxfb <<endl;
}
// D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define pq priority_queue

void v_print(VL v,int N){rp(i,0,N) printf("%d,",v[i]);puts("");}//

#define NMAX 100000
int N;
VL A(3*NMAX);

void f(VL &V, ll sign){
	pq<int> que;
	rp(i, 0, N){
		que.push(sign*A[i]);
		V[0] += A[i];
	}
	int j=0;
	rp(v, 0, N){
		int a = N + v;
		que.push(sign*A[a]);
		V[v+1] += V[v] + A[a] - sign*que.top();
		que.pop();
	}
}

int main(){
	cin>>N;
	int N3 = N*3;
	rp(i, 0, N3) cin>>A[i];

	VL F(N+1), B(N+1);
	f(F, -1L);
	reverse(A.begin(), A.begin()+N3);
	f(B, 1L);

	ll maxfb = LLONG_MIN;
	rp(f, 0, N+1){
		int b = N - f;
		maxfb = max(maxfb, F[f]-B[b]);
	}
	cout<< maxfb <<endl;
}
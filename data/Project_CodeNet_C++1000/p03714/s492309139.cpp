// D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)
#define pq priority_queue

void v_print(VL v,int N){rp(i,0,N) printf("%d,",v[i]);puts("");}//

void pq_print(pq<int> q){printf("[");while(!q.empty()){printf("%d,",q.top());q.pop();}puts("]");}//

#define NMAX 100000
int N;
VL A(3*NMAX);

int main(){
	cin>>N;
	int N2 = N*2;
	int N3 = N*3;
	rp(a, 0, N3) cin>>A[a];

	VL F(N+1);
	pq<int> fque;
	rp(a, 0, N){
		fque.push(-A[a]);
		F[0] += A[a];
	}
	rp(f, 0, N){
		int a = N + f;
		fque.push(-A[a]);
		F[f+1] += F[f] + A[a] - (-fque.top());
		fque.pop();
	}

	VL B(N+1);
	pq<int> bque;
	irp(a, N3-1, N2-1){
		bque.push(A[a]);
		B[N] += A[a];
	}
	for(int a=N2-1, b=N-1; b>0-1; --b, --a){
		bque.push(A[a]);
		B[b] = B[b+1] + A[a] - (bque.top());
		bque.pop();
	}

	ll maxfb = LLONG_MIN;
	rp(i, 0, N+1){
		maxfb = max(maxfb, F[i]-B[i]);
	}
	cout<< maxfb <<endl;
}
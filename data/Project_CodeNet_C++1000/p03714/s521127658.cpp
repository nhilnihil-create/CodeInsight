// D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define pq priority_queue
#define pb push_back

int main(){
	int N; cin>>N;

	int N2 = N*2, N3 = N*3;
	VL A1, A2, A3, F(N+1), B(N+1);
	ll fsum = 0, bsum = 0;
	pq<int> fque, bque;

	rp(i, 0, N3){
		int a;cin>>a;
		if(i < N){
			fque.push(-a);
			fsum += a;
			A1.pb(a);
		}
		else if(i >= N2){
			bque.push(a);
			bsum += a;
			A3.pb(a);
		}
		else A2.pb(a);
	}

	F[0] = fsum;
	for(int i=0; i<N; ++i){
		fque.push(-A2[i]);
		fsum += A2[i] - (-fque.top());
		F[i+1] = fsum;
		fque.pop();
	}

	B[N] = bsum;
	for(int i=N-1; i>-1; --i){
		bque.push(A2[i]);
		bsum += A2[i] - (bque.top());
		B[i] = bsum;
		bque.pop();
	}

	ll maxfb = LLONG_MIN;
	rp(i, 0, N+1) maxfb = max(maxfb, F[i]-B[i]);
	cout<< maxfb <<endl;
}
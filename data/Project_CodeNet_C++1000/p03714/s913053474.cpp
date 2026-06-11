// D - 3N Numbers
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rp(i,n) for(int i=0;i<(n);++i)
#define ote(x) cout<<(x)<<endl
#define all(x) (x).begin(),(x).end()

void pq_print(priority_queue<int> q){
	printf("[");
	while(!q.empty()){
		printf("%d,",q.top());q.pop();
	// }puts("]\n--");
	}puts("]");
}

void v_print(vector<ll> v){
	for(auto e:v) printf("%d,",e);puts("");
}

int main(){
	int N; cin>>N;
	vector<ll> A(3*N);
	rp(i, 3*N) cin>>A[i];

	// v_print(A);//

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

		// pq_print(fque);//
		// v_print(F);//

	}

	reverse(all(A));

	// puts("--");//
	// v_print(A);//

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

		// pq_print(bque);//
		// v_print(B);//

	}

	B.pop_back();
	reverse(all(B));

	// v_print(F);//
	// v_print(B);//

	ll maxfb = LLONG_MIN;
	rp(i, N+1){
		int j = N - 1 + i;
		maxfb = max(maxfb, F[j]-B[j]);
	}
	cout<< maxfb <<endl;

}

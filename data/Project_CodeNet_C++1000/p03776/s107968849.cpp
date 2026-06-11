// D - Maximum Average Sets
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using DBL = double;
#define allr(x) (x).rbegin(),(x).rend()
#define rp(i,s,e) for(ll i=(s);i<(e);++i)
#define rpz(i,e) rp(i,0,e)
#define MAX 50

vvl nCr(MAX+1, vl(MAX+1, 0));

void nCr_table_create(ll N){
	rp(n, 0, N+1) rp(r, 0, n+1){
		if(r==0 || n==r) nCr[n][r] = 1;
		else nCr[n][r] = nCr[n-1][r-1] + nCr[n-1][r];
	}
}

int main(){
	int N,A,B; cin>>N>>A>>B;
	vl V(N); rpz(i, N) cin>>V[i];
	sort(allr(V));

	nCr_table_create(N);

	DBL maxave = 0.0;
	rpz(i, A) maxave += V[i];
	maxave /= A;

	int n = 0, r = 0;
	rpz(i, N){
		if(V[A-1] == V[i]){
			n++;
			if(i < A) r++;
		}
	}

	ll maxcnt = 0;
	// if(r == A) rp(r, A, B+1) maxcnt += nCr[n][r];
	if(r == A) rp(r, A, min(n, B)+1) maxcnt += nCr[n][r];
	else maxcnt = nCr[n][r];

	printf("%.6f\n", maxave);
	cout<< maxcnt <<endl;
}
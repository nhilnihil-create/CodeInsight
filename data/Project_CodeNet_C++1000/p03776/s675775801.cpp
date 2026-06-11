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

vvl nCr_table(MAX+1, vl(MAX+1, 1));

void nCr_table_create(ll N){
	rp(n,1,N+1) rp(r,1,N+1-n)
		nCr_table[n][r] = nCr_table[n-1][r] + nCr_table[n][r-1];
}

ll nCr(int n, int r){
	if(n < r) return 0;
	int i = n - r;
	int j = r;
	return nCr_table[i][j];
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
	ll v = V[A-1];
	rpz(i, N){
		if(v == V[i]){
			n++;
			if(i < A) r++;
		}
	}

	ll maxcnt = 0;
	if(r == A) rp(r, A, B+1) maxcnt += nCr(n, r);
	else maxcnt = nCr(n, r);

	printf("%.6f\n", maxave);
	cout<< maxcnt <<endl;
}
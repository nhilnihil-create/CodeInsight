#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll C[51][51];

void comb_table(int n){
	rep(i,n+1)rep(j,i+1){
		if(j == 0 || j == i){
			C[i][j] = 1LL;
		}
		else{
			C[i][j] = (C[i-1][j-1] + C[i-1][j]);
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, A, B;
	cin >> n >> A >> B;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	comb_table(n);
	sort(v.rbegin(), v.rend());
	double ma = 0.0;
	rep(i,A) ma += v[i];
	ma /= A;
	int a_th_val_num = 0, a_th_val_pos = 0;
	rep(i,n){
		if(v[i] == v[A-1]){
			a_th_val_num++;
			if(i < A){
				a_th_val_pos++;
			}
		}
	}
	ll cnt = 0LL;
	if(a_th_val_pos == A){
		for(a_th_val_pos = A; a_th_val_pos <= B; a_th_val_pos++){
			cnt += C[a_th_val_num][a_th_val_pos];
		}
	}
	else{
		cnt += C[a_th_val_num][a_th_val_pos];
	}
	cout << fixed << setprecision(12) << ma << endl;
	cout << cnt << endl;
	return 0;
}
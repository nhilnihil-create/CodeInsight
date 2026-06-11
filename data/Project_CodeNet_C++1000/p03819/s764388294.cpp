#include <bits/stdc++.h>
using namespace std;
int M, N, M_; 
int seg[262200], lazy[262200]; 
void init(int M_){
	M = 1; 
	while(M < M_) M *= 2; 
	for(int i = 0; i < M * 2 - 1; i++){
		seg[i] = 0; lazy[i] = 0;  
	}
}
void update(int k){
	if(lazy[k] == 0) return; 
	seg[k] += lazy[k]; 
	if(k * 2 + 2 < M * 2 - 1){
		lazy[k * 2 + 1] += lazy[k] / 2; 
		lazy[k * 2 + 2] += lazy[k] / 2; 
	}
	lazy[k] = 0; 
}
void add(int a, int b, int k, int l, int r, int x){
	update(k); 	
	if(b <= l || r <= a) return; 
	if(a <= l && r <= b){
		lazy[k] += x * (r-l); 
		update(k); 
	}else{
		add(a, b, k * 2 + 1, l, (l+r)/2, x);
		add(a, b, k * 2 + 2, (l+r)/2, r, x);
		seg[k] = seg[k * 2 + 1] + seg[k * 2 + 2];
	}
}
int query(int a, int b, int k, int l, int r){
	if(b <= l || r <= a) return 0; 
	update(k); 
	if(a <= l && r <= b) return seg[k];
	int vl = query(a, b, k * 2 + 1, l, (l+r)/2);
	int vr = query(a, b, k * 2 + 2, (l+r)/2, r);
	return vl + vr; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M_;
	init(M_);
	pair<int, pair<int, int>> A[300010]; 
	for(int i = 0; i < N; i++){
		cin >> A[i].second.first >> A[i].second.second;
		A[i].first = A[i].second.second - A[i].second.first;
		A[i].second.first --; A[i].second.second --;
	}
	sort(A, A+N); 
	int id = 0;
	for(int q = 1; q <= M_; q++){
		while(A[id].first < q-1 && id < N){
			int l = A[id].second.first; 
			int r = A[id].second.second; 
			add(l, r+1, 0, 0, M, 1); 
			id++; 
		}
		int ans = N - id;
		for(int i = q - 1; i < M_; i += q){
			ans += query(i, i+1, 0, 0, M);
		}
		cout << ans << "\n"; 
	}
}
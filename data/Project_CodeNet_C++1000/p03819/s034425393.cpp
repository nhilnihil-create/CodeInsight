#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M,l,r;

ll bit0[300010] = {0},bit1[300010] = {0};
ll sum(ll *b,ll i){
	ll s = 0;
	while(i>0){
		s += b[i];
		i -= i&-i;
	}
	return s;
}

void add(ll *b,int i,ll v){
	while(i<=M){
		b[i] += v;
		i += i&-i;
	}
}

void seg_add(int l,int r, ll x){
	add(bit0,l,-x*(l-1));
	add(bit1,l,x);
	add(bit0,r+1,x*r);
	add(bit1,r+1,-x);	
}

ll seg_sum(int l, int r){
	ll res = 0;
	res += sum(bit0,r) + sum(bit1,r)*r;
	res -= sum(bit0,l-1) + sum(bit1,l-1)*(l-1);
	return res;
}


int main(){
	cin >> N >> M;
	vector<vector<P>> v(M+1);
	for(int i=0;i<N;i++){
		cin >> l >> r;
		v[r-l+1].push_back({l,r});
	}
	int sum = N;
	for(int i=1;i<=M;i++){
		int ans = sum;
		for(int j=1;j*i<=M;j++){
			ans += seg_sum(i*j,i*j);
		}
		cout << ans << endl;
		for(int j=0;j<v[i].size();j++){
			seg_add(v[i][j].first,v[i][j].second,1);
			sum--;
		}
	}
}
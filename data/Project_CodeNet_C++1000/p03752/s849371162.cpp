#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << "   ";
		}
		cout << endl;
	}
}





int main(){//
	int N, K;
	cin >> N >> K;
	vector<ll> a(N);
	for(int i=0; i<N; i++) cin >> a[i];

	//bit全探索
	//1のところのビルが色が見えるようにする
	ll ans = 1001001001001001;
	for(int i=0; i< (1<<N); i++){
		bitset<15> bit(i);//iを2進数表記で格納
		if(bit.count() != K) continue;//1の個数がK個でないとだめ(K個より多いと無駄がでる)

		
		vector<ll> b = a;
		ll height = b[0];//注目ビルより前のビルたちの最大高さを格納
		ll yen = 0;
		for(int j=1; j<N; j++){
			if(bit[j] == 0){
				height = max(height, b[j]);
				continue;
			}
			
			if(height >= b[j]){//注目ビルより前に，高いビルがあるなら
				height = height+1;
				yen += height - b[j];
				//b[j] = height;
			}
			else{
				height = b[j];
				//yen += 0;//注目ビルは高くしなくて良い
			}			
		}

		// if(yen == 0){
		// 	cout << " bit: " << bit << " bit[0]: " << bit[0] <<  endl;
		// 	cout << " b: "; print_vec(b);
		// }
		ans = min(ans, yen);
	}

	cout << ans << endl;
}

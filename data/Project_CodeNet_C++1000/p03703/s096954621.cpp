#include "bits/stdc++.h"
using namespace std;
using lint = long long;

struct BIT{
  vector<int> bit;
  int N;
  BIT() {init();}
  BIT(int N) : N(N){init();}
  void init(){
    bit.clear();
    bit.resize(N + 1,0);
  }
  int sum(int i){
    int s = 0;
    while(i > 0){
      s += bit[i];
      i -= i&-i;
    }
    return s;
  }
  void add(int i,int x){
    while(i <= N){
      bit[i] += x;
      i += i & -i;
    }
  }
};

signed main(){
	lint N, K; cin >> N >> K;
	vector<lint> sum(N + 1, 0);
	for(int i = 0; i < N; i++){
		lint x; cin >> x; sum[i + 1] = sum[i] + x - K;
	}
	vector<lint> ss = sum, comp(N + 1);
	sort(ss.begin(), ss.end());
	ss.erase(unique(ss.begin(), ss.end()), ss.end());
	for(int i = 0; i <= N; i++){
		comp[i] = lower_bound(ss.begin(), ss.end(), sum[i]) - ss.begin();
	}
	BIT bit(500000);
	lint ans = 0;
	for(lint j = 0; j <= N; j++){
		ans += bit.sum(comp[j] + 1);
		bit.add(comp[j] + 1, 1);
	}
	cout << ans << endl;
}
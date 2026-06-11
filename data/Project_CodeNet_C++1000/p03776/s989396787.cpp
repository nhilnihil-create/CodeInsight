#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll comb(int n, int r) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v[n][r];
}

int main(void){
  cout << setprecision(10);
  int N,A,B;
  cin >> N >> A >> B;
  map<ll, int> m;
  ll min_val = 0;
  for(int i = 0; i < N; i++){
    ll tmp;
    cin >> tmp;
    tmp *= -1;
    if(m.count(tmp) == 0){
      m[tmp] = 1;
    } else { 
      m[tmp] += 1;
    }
    if(tmp < min_val){
      min_val = tmp;
    }
  }
  
  int num = 0;
  ll  sum = 0;
  ll last_num = 0;
  for(auto x: m){
    if(num + x.second >= A){
      last_num = x.first;
      sum += -x.first * (A - num);
      break;
    } else { 
      num += x.second;
      sum += -x.first * x.second;
    }
  }
  cout << setprecision(20) << (double)sum / (double)A << endl;

  // A - num 個を、v[last_num]個から選ぶ
  int p = A - num;
  int q = m[last_num];
  ll ans = 0;
  if(num == 0){ // 最初が全ての場合, A個でもB個でも同じ
    for(int i = A; i <= min(B, q); i++){
      ans += comb(q, i);
    }
  } else { 
    ans = comb(q, p);
  }
  cout << ans << endl;
}


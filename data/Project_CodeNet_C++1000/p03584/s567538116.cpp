#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;

  vector<pair<int, int>> AB(N);
  for(int i = 0; i < N; i++){
    int a, b;
    cin >> a >> b;
    AB[i] = make_pair(a, b);
  }

  int zero_mask = 0;
  long long ans = 0;
  for(int i = 29; i >= 0; i--){
    if(((K >> i) & 1) == 0){
      zero_mask |= (1 << i);
    }else{
      zero_mask |= (1 << i);
      long long ans_tmp = 0;
      for(int j = 0; j < N; j++){
        if((AB[j].first & zero_mask) == 0){
          ans_tmp += AB[j].second;
        }
      }
      ans = max(ans, ans_tmp);
      zero_mask ^= (1 << i);
    }
  }

  long long ans_tmp = 0;
  for(int i = 0; i < N; i++){
    if((AB[i].first & zero_mask) == 0){
      ans_tmp += AB[i].second;
    }
  }
  ans = max(ans, ans_tmp);

  cout << ans << endl;
}

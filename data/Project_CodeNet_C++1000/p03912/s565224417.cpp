#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  map<int, int> num_cnt;
  for(int i = 0; i < N; i++){
    int x;
    cin >> x;
    num_cnt[x]++;
  }

  long long ans = 0;
  vector<multiset<int>> res_cnt(M);
  vector<int> res_cnt_sum(M);
  for(auto pair: num_cnt){
    res_cnt[pair.first % M].insert(2 * (pair.second / 2));
    if(pair.second % 2){
      res_cnt[pair.first % M].insert(1);
    }
    res_cnt_sum[pair.first % M] += pair.second;
  }

  for(int i = 0; i * 2 <= M; i++){
    if((i == 0) || (i * 2 == M)){
      ans += res_cnt_sum[i] / 2;
      res_cnt_sum[i] %= 2;
    }else{
      int si, li;
      if(res_cnt_sum[i] <= res_cnt_sum[M - i]){
        si = i;
        li = M - i;
      }else{
        si = M - i;
        li = i;
      }
      for(auto x: res_cnt[li]){
        if(res_cnt_sum[si] > 0){
          int diff = min(res_cnt_sum[si], x);
          res_cnt_sum[si] -= diff;
          x -= diff;
          ans += diff;
        }
        ans += x / 2;
      }
    }
  }


  cout << ans << endl;
}

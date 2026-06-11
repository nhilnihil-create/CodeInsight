#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int N;
  std::string s, t;
  std::cin >> N >> s >> t;
  int cnt = 0;
  for(int i = 0; i < N;i++){
    int tmp = cnt;
    rep(j,N-i){
      if(s[i+j] != t[j]){
        cnt++;
        break;
      }
    }
    if(tmp == cnt)
      break;
  }

  std::cout << N + cnt << '\n';
  return 0;
}

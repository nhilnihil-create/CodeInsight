#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,T;
  cin >> N >> T;

  int t_prev, t_tmp;
  cin >> t_prev;
  int ans= 0;
  for(int i=1; i<N; i++){
    cin >> t_tmp;
    if(t_tmp- t_prev < T){
      ans+= t_tmp- t_prev;
      t_prev= t_tmp;
    }
    else{
      ans+= T;
      t_prev= t_tmp;
    }
  }
  ans+= T;

  cout << ans << endl;
}
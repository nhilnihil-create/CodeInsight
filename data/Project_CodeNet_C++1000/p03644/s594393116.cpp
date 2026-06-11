#include <bits/stdc++.h>
using namespace std;
main(){
  int N;
  cin >> N;
  int max_cnt = 0;
  for(int i=0;i<N;i++){
    int cnt=0;
    int n = N-i;
    while(true){
      if(n%2==0){
      n/=2;
      cnt++;
      max_cnt=max(cnt,max_cnt);
      } else {break;}
    }
  }
  int max_cnt_two=1;
  for(int i=0;i<max_cnt;i++){
    max_cnt_two*=2;
  }
  cout << max_cnt_two << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
1 x x x 5
1 3 5 7 5
7 x x 6 4-5
7 2 6 6 OUT
7-6=1
1/4=0
1/5=0
xが奇数ならOKだった

1 x x 5 4-6
4/6=0
4/4=1
2-1=1 OK
繰り返しに至れるか
最低値と最高値で何回でいたるか
普通に全探索N通りでいけるじゃん
*/
int main(){
  ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
  for(int i=0; i<N; i++){//最大をとる回数
    ll cnt=N-i-1;
    ll high=D*i-C*cnt;
    ll low=C*i-D*cnt;
    if(B-A<=high && B-A>=low){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int N=0, A=-1;
  cin >> N >> A;
  if(N<1||100<N||A<0||N*N<A)
    cout << "入力エラー(制約 : 1≦N≦100, 0≦A≦N*N)" << endl;
  else cout << (N*N)-A << endl;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int N;
  cin >> N;
  int cnt = 0;
  //vector<int> A(N);
  rep(i, N){
    int a;
    cin >> a;
    if(a % 2 != 0){
      cnt++;
    }
  }
  if(cnt % 2 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}

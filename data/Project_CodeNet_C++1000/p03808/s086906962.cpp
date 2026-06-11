#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  ll N;
  cin >> N;
  ll a[N];
  ll sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }

  //一回の操作で取り除く石の数
  ll S = N * (N + 1) / 2;
  if(sum % S != 0){
    //cout << "hoge" << endl;
    cout << "NO" << endl;
    return 0;
  }
  //操作回数
  ll T = sum / S;

  //右の項との差分b
  ll b[N];
  for(int i = 0; i < N - 1; i++){
    b[i] = a[i+1] - a[i];
  }
  b[N-1] = a[0] - a[N-1];

  //iがm回選ばれるとすると、
  //-m(N-1)+(T-m)=b[i]
  //m=(T-b)/N;

  //選ばれる回数m
  ll m[N];
  for(int i = 0; i < N; i++){
    ll tmp = T - b[i];
    if(tmp % N != 0 || tmp < 0){
      //cout << i << endl;
      //cout << "Hoge1" << endl;
      cout << "NO" << endl;
      return 0;
    }
    m[i] = tmp / N;
  }

  ll cnt = 0;
  for(int i = 0; i < N; i++) cnt += m[i];

  if(cnt != T){
    //cout << "Hoge12" << endl;
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string s;
  ll K;
  cin >> s;
  int N = s.size();
  cin >> K;
  string A = "abcdefghijklmnopqrstuvwxyz";

  int last_index = N-1;
  for(int i = 0; i < N-1; i++){
    // aにするまでの回数
    int num;
    num = 'z' - s[i] + 1;
    num %= 26;

    if(num <= K){
      // aにする
      s[i] = 'a';
      K -= num;
    } else { 
      // aにできない
      continue;
    } 
  }
  
  //後処理
  int tmp = s[N-1] - 'a';
  int next = tmp + K;
  next %= 26;
  s[N-1] = A[next];

  cout << s << endl;
  
}

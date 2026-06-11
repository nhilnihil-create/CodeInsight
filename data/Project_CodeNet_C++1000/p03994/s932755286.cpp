#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int K; cin >> K;
  int N = s.size(), i = 0;
  string ANS = "";
  while(K > 0){
    if(i == N - 1){
      ANS += 'a' + ((s[i] - 'a') + K % 26) % 26;
      break;
    }
    if(s[i] == 'a'){
      ANS += 'a';
      i++;
    }else{
      if('z' - s[i] + 1 <= K){
        ANS += 'a';
        K -= 'z' - s[i] + 1;
        i++;
        if(K == 0){
          while(i < N){
            ANS += s[i];
            i++;
          }
        }
      }else{
        ANS += s[i];
        i++;
      }
    }
  }
  cout << ANS << endl;
}
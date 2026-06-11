#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main() {
  int N, A, B;
  string S;
  cin >> N >> A >> B >> S;
  int pass = 0;
  int passb =0;
  rep(i,S.size()){
    if (S[i] == 'b') passb++;
    if(S[i] == 'a' && pass < A + B ){
      pass++;
      cout << "Yes" << endl;
    } else if (S[i] == 'b' && pass < A + B && passb <= B) {
      pass++;
      cout << "Yes" << endl;  
    } else{
      cout << "No" << endl;
    }
  }


	return 0;
}


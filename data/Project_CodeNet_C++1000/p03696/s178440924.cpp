#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  string S; cin >> S;
  stack<char> st;
  deque<char> dq;
  REP(i, N){
    if(S[i] == '('){
      st.push('(');
      dq.push_back('(');
    }else if(S[i] == ')' && st.empty()){
      dq.push_front('(');
      dq.push_back(')');
    }else{
      dq.push_back(')');
      st.pop();
    }
  }
  if(!st.empty()){
    REP(i, st.size()){
      dq.push_back(')');
    }
  }
  while(!dq.empty()){
    char ans = dq.front(); dq.pop_front();
    cout << ans;
  }
  cout << endl;
}
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
  REP(i, N){
    if(st.empty()){
      st.push(S[i]);
    }else{
      char C = st.top();
      if(C == '(' && S[i] == ')'){
        st.pop();
      }else{
        st.push(S[i]);
      }
    }
  }
  int a = 0, b = 0;
  while(!st.empty()){
    char C = st.top(); st.pop();
    if(C == ')') a++;
    if(C == '(') b++;
  }
  REP(i, a){
    cout << "(";
  }
  cout << S;
  REP(i, b){
    cout << ")";
  }
  cout << endl;
}
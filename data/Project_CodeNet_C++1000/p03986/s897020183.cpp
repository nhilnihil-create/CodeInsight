#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(a) (a.begin(),a.end())
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  string s;
  cin >> s;
  deque<char>st;
  st.push_back(s[0]);
  REP(i,1,s.size()){
    char now = s[i];
    char mae = 'T';
    if(st.size() != 0)mae = st.back();
    if(mae == 'S'){
      if(now == 'T')st.pop_back();
      else st.push_back('S');
    }
    else{
      st.push_back(now);
    }
  }
  string ans;
  cout << st.size() << endl;
  return 0;
}

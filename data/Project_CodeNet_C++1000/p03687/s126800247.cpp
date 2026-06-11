#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
template <typename T, typename U>
using P = pair<T,U>;
template <typename T>
using vt = vector<T>;
using vvi = vector<vector<int>>;

int main(){
  string s;
  cin >> s;
  map<char,int> alp;
  int max_alp = 0, size = s.size();
  rep(i,size){
    char a = s[i];
    alp[a]++;
    if(max_alp < alp[a]){
      max_alp = alp.at(a);
    }
  }
  
  if(alp.size()==1)
    cout << 0 << endl;
  else if(max_alp == 1)
    cout << size/2 << endl;
  else{
    int ans = size/2;
    for(auto x : alp){
      char c = x.first;
      int tmp_ans = 0, tmp_c=-1;
      rep(i,size){
        if(s[i]==c){
          tmp_ans = max(tmp_ans, i-tmp_c-1);
          tmp_c = i;
        }
        else if(i == size - 1)
          tmp_ans = max(tmp_ans, i-tmp_c);
      }
      ans = min(ans,tmp_ans);
    }
    cout << ans << endl;
  }

  return 0;
}
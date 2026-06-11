#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 1e9+7;
/*int dfs(vector<int> &T, vector<int> &C, int i, int sum, int g, int count){
   
}*/
bool all_string(string s){
  int sz = s.size();
  rep(i, sz-1){
    if(s.at(i)!=s.at(i+1)) return false;
  }
  return true;
}

int main(){
  string s;
  cin >> s;
  int sz = s.size();
  char m;
  string t = "";
  string p = s;
  int i;
  int ch = 0;
  int ans = 0;
  if(all_string(p)) cout << 0 << endl;
  else{
    for(m='a'; m<='z'; ++m){
    while(!(all_string(p))){
    int szt = p.size();  
    //cout << szt << endl;
    for(i=0; i<szt-1; i++){
      if(m==p.at(i)||m==p.at(i+1)) {t = t + m; ch = 1;}
      else t = t+p.at(i);
    }
    //cout << t << endl;
    if(ch==0) {p=s; t=""; break;}
    else {p = t; t = "";}
    }
    if(ch==1){
    ch = 0;
    int l = p.size();
    ans = max(ans, l);
    t = ""; p = s;}
  }
  cout << sz-ans << endl;
  //string t = s;
  //sort(t.begin(), t.end());
  }

  //int ch = all_string(s, sz);
  //cout << ch << endl;
}


#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string t; cin >> t;
  set<char> chars;
  rep(i,t.size()) chars.insert(t[i]);
  if (chars.size()==1){
    cout << 0 << endl;
    return 0;
  }
  
  int retval = 1000;
  for (char c : chars){
    int cnt = 0;
    string tt = t;
    rep(j,t.size()){
      
      rep(i,tt.size()-1){
        char ap;
        if (tt[i]==c || tt[i+1]==c) tt[i] = c;
        else tt[i] = t[i];
      }
      tt.erase(tt.size()-1);
      cnt++;
      bool all_same = true;
      rep(i,tt.size()) if (tt[i]!=tt[0]) all_same = false;
      if (all_same) break;

            
    }

    retval = min(retval, cnt);
  }
  cout << retval << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}


#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;

  int find_A,find_Z_last;  
  rep(i,s.size())
    if(s[i] == 'A'){      
      find_A = i;
      break;
    }  
  for(int i = s.size()-1;i>=0;--i)
    if(s[i] == 'Z'){
      find_Z_last = i;
      break;
    }

  int ans = find_Z_last-find_A+1;
  cout << ans << endl;
  
  return 0;
}

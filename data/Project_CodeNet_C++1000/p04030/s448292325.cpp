#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S; cin >> S;
  string ans = "";
  for(int i = 0; i < S.size(); i++){
    if(S[i] == 'B'){
      if(ans.size() == 0){
        continue;
      } else { 
        ans.erase(ans.size()-1);
      } 
    } else { 
      ans += S[i];
    }
  }
  cout << ans << endl;
}

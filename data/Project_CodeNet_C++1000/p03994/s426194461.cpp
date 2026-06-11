#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string S;
  ll K;
  cin >> S;
  cin >> K;

  string ans = "";
  for(char c: S){
    if(c == 'a'){
      ans += "a";
    } else {
      ll tmp = 'z' - c + 1;
      if(K >= tmp){
        K -= tmp;
        ans += "a";
      } else {
        ans += c;
      }
    }
  }
  if(K > 0){
    char c = ans[ans.size()-1];
    K %= 26;
    char add;
    if('z' - c >= K){
      add = c + K;
    } else { 
      K -= 'z' - c - 1;
      add = 'a' + K;
    }

    ans[ans.size()-1] = add;
  }
  cout << ans << endl;

}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int n,a,b;string s;
  cin >> n >> a >> b >> s;
  int now = a + b, cnt = 0;
  for(int i = 0; i < n; i++){
    if(now == 0) cout << "No" << endl;
    else if(s[i] == 'c') cout << "No" << endl;
    else if(s[i] == 'a'){
      cout << "Yes" << endl;
      now--;
    }else{
      if(cnt >= b) cout << "No" << endl;
      else{
        cout << "Yes" << endl;
        now--;
        cnt++;
      }
    }
  }
  return 0;
}

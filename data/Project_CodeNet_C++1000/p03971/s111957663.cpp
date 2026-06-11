#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  int cnt_tot = 0;
  int cnt_foreign = 0;

  rep(i,n) {
    if(s[i] == 'a'){
      if(cnt_tot < a+b) {cout << "Yes" << endl; cnt_tot++;}
      else cout << "No" << endl;
    }
    else if(s[i] == 'b'){
      if(cnt_tot < a+b && cnt_foreign+1 <= b) {
        cout << "Yes" << endl;
        cnt_tot++;
        //cnt_foreign++;
      }
      else {cout << "No" << endl;}
      cnt_foreign++;
    }
    else {
      cout << "No" << endl;
      //cnt_tot++;
    }
  }
  
}

#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main() {
  int H,W;
  cin>>H>>W;
  string s[100];
  for(int i(0);i<H;i++){
    cin>>s[i];
  }
  int cnt[30] = {0};
  for(int h(0);h<H;h++){
    for(int w(0);w<W;w++){
      cnt[s[h][w]-'a']++;
    }
  }
  for(int i(0);i<30;i++){
    cnt[i] %= 4;
  }
  if(H%2 == 0 && W%2 == 0){
    for(int i(0);i<30;i++){
      if(cnt[i] != 0){
        cout << "No" << endl;
        return 0;
      }
    } 
    cout << "Yes" << endl;
  }else if(H%2 == 1 && W%2 == 1){
    int odd(0),even(0);
    for(int i(0);i<30;i++){
      if(cnt[i] %2 == 1) odd++;
      even += cnt[i]/2;
    }
    if(odd == 1 && even <= (W + H - 2)/2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }else{
    int guusuu;
    if(H%2 == 1) guusuu = W;
    else guusuu = H;
    int odd(0),even(0);
    for(int i(0);i<30;i++){
      if(cnt[i] %2 == 1) odd++;
      even += cnt[i]/2;
    }
    if(odd == 0 && even <= guusuu/2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
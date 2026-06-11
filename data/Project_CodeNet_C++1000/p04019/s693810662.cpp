#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const int M = 1000005;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> cnt(4);
  rep(i, n){
    if(s[i] == 'N') cnt[0]++;
    if(s[i] == 'S') cnt[1]++;
    if(s[i] == 'W') cnt[2]++;
    if(s[i] == 'E') cnt[3]++;
  }
  bool exist = true;
  if(cnt[0] != 0 && cnt[1]!= 0 && cnt[2] != 0 && cnt[3] != 0){
    exist = true;
  }else if(cnt[0] != 0 && cnt[1] != 0 && cnt[2] == 0 && cnt[3] == 0 ){
    exist = true;
  }else if(cnt[2] != 0 && cnt[3] != 0 && cnt[0] == 0 && cnt[1] == 0){
    exist = true;
  }else{
    exist = false;
  }
  if(exist) cout << "Yes" << endl;
  else cout << "No" << endl;

}
#include <bits/stdc++.h>
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
using namespace std;

int main(){
  string s;
  cin >> s;
  sort(s.begin(),s.end());
  bool flag = true;
  for(int i=1;i<=s.size();i++){
    if(s[i]==s[i-1]) flag = false;
    if(!flag) break;
  }
  if(!flag){
    cout << "no" << endl;
  }else{
    cout << "yes" << endl;
  }
}
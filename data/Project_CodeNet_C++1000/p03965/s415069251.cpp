#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  string s;
  cin >> s;
  int n=s.size();
  int gcnt=0;
  int pcnt=0;
  int ans=0;
  for(int i=0;i<n;++i){
    if(gcnt>pcnt){
      if(s[i]=='g') ans++;
      pcnt++;
    }else{
      if(s[i]=='p') ans--;
      gcnt++;
    }
  }
  cout << ans << endl;
  return 0;
}

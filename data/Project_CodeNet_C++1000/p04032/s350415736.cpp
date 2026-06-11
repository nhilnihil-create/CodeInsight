/* 解説通り実装 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s;
  cin>>s;
  int l = s.size();
  for(int i=0; i<l-2; i++){
    if(s[i]==s[i+1]){
      cout<<i+1<<" "<<i+2<<endl;
      return 0;
    }else if(s[i]==s[i+2]){
      cout<<i+1<<" "<<i+3<<endl;
      return 0;
    }
  }
  if(s[l-2]==s[l-1]){
    cout<<l-1<<" "<<l<<endl;
    return 0;
  }
  cout<<-1<<" "<<-1<<endl;
}
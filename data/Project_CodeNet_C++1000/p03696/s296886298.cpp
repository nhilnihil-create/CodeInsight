#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  string s;
  cin>>s;
  int migi=0;
  int hidari=0;
  int count_hidari=0;
  int count_migi=0;
  vector<bool> hantei(n);
  for(int j=0;j<n;j++){
    hantei[j]=0;
  }
  for(int j=0;j<n-1;j++){
    if(s[j]=='(' && hantei[j]==false){
      for(int k=j+1;k<n;k++){
        if(s[k]==')'&&hantei[k]==false){
          hantei[j]=true;
          hantei[k]=true;
          break;
        }
      }
    }
  }
  for(int i=0;i<s.size();i++){
    if(s[i]=='('&&hantei[i]==false)count_hidari++;
    else if(s[i]==')'&&hantei[i]==false)count_migi++;
  }
  for(int j=0;j<count_hidari;j++){
    s.push_back(')');
  }      
  for(int j=0;j<count_migi;j++){
    s.insert(0,"(");
  }
  cout<<s<<endl;
  return 0;
}
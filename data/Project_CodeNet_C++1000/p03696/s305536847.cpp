#include <bits/stdc++.h>
using namespace std;
//自分の解答の清書 
int main() {
  int n; cin >>n;
  string s;
  cin>>s;
  int cnt_l=0;
  int cnt_r=0;
  vector<bool> hantei(n,0);
  for(int i=0;i<n-1;i++){
    if(s[i]=='(' && hantei[i]==false){
      for(int j=i+1;j<n;j++){
        if(s[j]==')'&&hantei[j]==false){
          hantei[i]=true;
          hantei[j]=true;
          break;
        }
      }
    }
  }
  for(int i=0;i<s.size();i++){
    if(s[i]=='('&&hantei[i]==false)cnt_l++;
    else if(s[i]==')'&&hantei[i]==false)cnt_r++;
  }
  for(int j=0;j<cnt_l;j++)s.push_back(')');
  for(int j=0;j<cnt_r;j++)s.insert(0,"(");
  cout<<s<<endl;
  return 0;
}
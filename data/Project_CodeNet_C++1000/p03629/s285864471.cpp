#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  vector<int> v;
  int q=s.size();
  v.push_back(q);
  int now=1;
  bool used[26];
  vector<int> ans;
  fill(used,used+26,false);
  int cnt=0;
  for(int i=s.size()-1;i>=0;i--){
    int num=s[i]-'a';
    if(used[num]==false){
      cnt++;
      used[num]=true;
    }
    if(cnt==26){
      v.push_back(i);
      cnt=0;
      fill(used,used+26,false);
      now++;
    }
  }
  //cout<<v[0]<<v[1];return 0;
  int pla=0;
  for(;;){
    int li=v[v.size()-1];
    bool bo[26];fill(bo,bo+26,false);
    for(int i=pla;i<li;i++){
      int p=s[i]-'a';
      bo[p]=true;
    }
    int nu;
    for(int i=0;i<26;i++){
      if(bo[i]==false){
        ans.push_back(i);
        nu=i;
        v.pop_back();
        break;
      }
    }
    if(ans.size()==now)break;
    for(int i=li;i<v[v.size()-1];i++){
      int r=s[i]-'a';
      if(r==nu){
        pla=i+1;
        break;
      }
    }
  }
  for(int i=0;i<ans.size();i++){
    char u=ans[i]+'a';
    cout<<u;
  }
  cout<<endl;
}
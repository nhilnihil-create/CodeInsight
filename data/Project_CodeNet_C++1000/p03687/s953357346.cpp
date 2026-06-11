#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  map<char,int>a;
  int c=0;
  for(int i=s.size()-1;i>=0;i--){
    c=0;
    for(int j=i;j>=0;j--){
      if(s.at(j)==s.at(i)){
        a[s.at(i)]=max(a[s.at(i)],c);
        c=0;
      }else{
        c++;
      }
    }
    a[s.at(i)]=max(a[s.at(i)],c);
  }
  //for(auto x:a)
    //cout << x.first << "#" << x.second << endl;
  int ans=100;
  for(auto x:a){
    int i=0,k;
    while(s.at(s.size()-i-1)!=x.first)
      i++;
    k=max(x.second,i);
    ans=min(ans,k);
  }
  cout << ans << endl;
  return 0;
}
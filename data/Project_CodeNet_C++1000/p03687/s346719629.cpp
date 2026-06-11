#include <bits/stdc++.h>
using namespace std;
int a[26];
int main() {
  string s;
  cin>>s;
  int n=s.size();
  for(int i=0;i<n;i++){
    int x=s[i]-'a';
    a[x]++;
  }
  int kotae=n;
  for(int i=0;i<26;i++){
    int tmp=0;
    int nagasa=0;
    if(a[i]==n){
      cout<<0<<endl;
      return 0;
    }
    if(a[i]!=0){
      //cout<<a[i]<<" ";
      for(int k=1;k<=a[i];k++){
        for(int j=0;j<n;j++){
          if(s[j]==(char)(i+'a')){
            if(tmp==0){
              nagasa=max({j,j-tmp-1,nagasa});
            }else{
              nagasa=max(j-tmp-1,nagasa);
            }
            tmp=j;
          }
        }
        nagasa=max(nagasa,n-tmp-1);
        //cout<<nagasa<<" ";
        kotae=min(nagasa,kotae);
      }
    }
  }
  cout<<kotae<<endl;
  return 0;
}

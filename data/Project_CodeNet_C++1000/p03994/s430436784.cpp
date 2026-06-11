#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  string s;
  int k;
  cin>>s>>k;
  int n=s.size(); 
  rep(i,n){
    if(i==n-1){
      for(int j=0; j<k%26; j++){
        if(s[i]=='z') s[i]='a';
        else s[i]++;
      }
      break;
    }
    int t = ('z'-s[i]+1) % 26;
    if(t<=k){
      s[i]='a';
      k-=t;
    }
  }
  cout<<s<<endl;
}


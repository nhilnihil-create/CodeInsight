#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  string s;
  cin>>n>>s;
  int ch=0;
  int right=0,left=0;
  for(int i = 0; i < n; i++){
    if(s[i]==')'){
      if(ch>0) ch--;
      else left++;
    }else ch++;
  } 
  ch=0;
  for(int i = n-1; i >= 0; i--){
    if(s[i]=='('){
      if(ch>0) ch--;
      else right++;
    }else ch++;
  }
  string l,r;
  rep(i,left) l+='(';
  rep(i,right) r+=')';
  cout<< l+s+r <<endl;
}


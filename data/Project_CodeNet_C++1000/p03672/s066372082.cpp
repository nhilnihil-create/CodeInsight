#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
typedef pair<int,int> pii;
typedef vector<int> vi;
bool check(int len,vector<char>& str){
  bool flag = true;
  if((len+1)%2!=0){
    return false;
  }
  int mid = len/2;
  for(int i = 0;i<=mid;i++){
    if(str[i]!=str[mid+i+1])
      flag = false;
  }

  return flag;
}
void solve(){
  string s;
  cin>>s;
  int n = s.length();
  vector<char> str;
  for(int i = 0;i<n;i++){
    str.push_back(s.at(i));
  }
  for(int i = n-2;i>=0;i--){
    if(check(i,str)==true){
      cout<<i+1;
      return;
    }
  }

  cout<<0;
  return;

  
}

int main(){
  solve(); 
}
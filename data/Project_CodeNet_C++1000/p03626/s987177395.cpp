#include<iostream>
#include<string>
using namespace std;
int p = 1000000007;
int main()
{
  int n,i;
  long long res;
  string s,t;
  cin >> n;
  cin >> s >> t;
  if(s[0]==t[0]){
    res=3;
    i=1;
  }else{
    res=6;
    i=2;
  }
  for(;i<n;i++){
    if(s[i]==t[i]){
      if(s[i-1]==t[i-1]){
        res*=2;
        res%=p;
      }
    }else{
      if(s[i-1]==t[i-1]){
        res*=2;
      }else{
        res*=3;
      }
      res%=p;
      i++;
    }
  }
  cout << res << endl;
  return 0;
}
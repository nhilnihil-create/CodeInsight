#include<iostream>
#include<string>
using namespace std;

const long long MOD=1e9+7;

int main(){
  int N;cin>>N;
  string s,s2;
  cin>>s>>s2;
  long long ans;
  int n;
  int sw=1;
  if(s[0]!=s[1]){
    ans=3;
    n=1;
  }else{
    ans=6;
    n=2;
    sw*=-1;
  }
  while(n<N){
    if(sw==1){
      if(n==N-1||s[n]!=s[n+1]){
        ans*=2;
        ans%=MOD;
        n++;
      }else if(s[n]==s[n+1]){
        ans*=2;
        ans%=MOD;
        n+=2;
        sw*=-1;
      }
    }else if(sw==-1){
      if(n==N-1||s[n]!=s[n+1]){
        ans*=1;
        ans%=MOD;
        n++;
        sw*=-1;
      }else if(s[n]==s[n+1]){
        ans*=3;
        ans%=MOD;
        n+=2;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
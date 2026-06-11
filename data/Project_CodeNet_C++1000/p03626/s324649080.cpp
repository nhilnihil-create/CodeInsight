#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int main(){
  ll mod=1000000007;
  int N;
  cin >> N;
  string s1,s2;
  cin >>s1 >> s2;
  ll ans =0;
  if(s1[0]==s2[0]) ans=3;
  else ans=6;
  for(int i=ans/3;i<N;i++){
    if(s1[i]==s2[i]){
      if(s1[i-1]==s2[i-1])ans = (ans*2)%mod;
      else ans = ans*1;
    }       
    else{
      if(s1[i-1]==s2[i-1])ans = (ans*2)%mod;
      else ans = (ans*3)%mod;
      i++;
    }
  }
  cout << ans << endl;
  return 0;

}

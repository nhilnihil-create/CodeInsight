#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<bitset>
#include<math.h>
using namespace std;
#define INF 110000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;


int main(){
  ll ans=1;
  int N,pre=0;
  string s;
  cin>>N>>s;

  for(int i=0;i<(int)s.size();i++,ans%=MOD){
    if(s[i]==s[i+1]){
      i++;
      if(pre==0) ans*=6;
      else if(pre==1) ans*=2;
      else if(pre==2) ans*=3;
      pre=2; 
    }else{
      if(pre==0) ans*=3;
      else if(pre==1) ans*=2;
      else if(pre==2) ans*=1;
      pre=1;
    }
  }
  cout<<ans<<endl;
}

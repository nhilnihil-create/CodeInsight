#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll ai,ao,at,aj,al,as,az;
  cin >>ai >> ao >> at >> aj >> al >> as >> az;
  ll ans=0;
  ll san;
  if(ai>0&&aj>0&&al>0){
    san=1LL;
    ans +=san*3LL;
    ans +=(ai-san)/2LL * 2LL;
    ans +=(aj-san)/2LL * 2LL;
    ans +=(al-san)/2LL * 2LL;
    ans +=ao;
  }
  ll ans2=0;
  san=0;
  ans2 +=san;
  ans2 +=(ai-san)/2LL * 2LL;
  ans2 +=(aj-san)/2LL * 2LL;
  ans2 +=(al-san)/2LL * 2LL;
  ans2 +=ao;
  cout <<  max(ans,ans2) << endl;
    
  
  


  
  return 0;
    

}

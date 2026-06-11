#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define dmp(x) cerr<<#x<<":"<<x<<endl
#define FOR(i,a,b) for(int i=(int)a,c=(int)b;i<c;++i)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=b-1,c=(int)a;i>=c;--i)
#define per(i,b) ROF(i,0,b)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

signed main(){
  int n,mod=1000000007;
  cin>>n;
  vector<int> x(n);
  rep(i,n)cin>>x[i];
  x[0]=1;
  int ans=1;
  int cnt=0;
  int recnt=0;
  rep(i,n){
    if(x[i]<(cnt+1)*2-1){
	 ans*=(cnt+1);
	 ans%=mod;
	 recnt++;
    }else cnt++;
  }
  dmp(recnt);dmp(cnt);
  FOR(i,recnt,n){
    ans*=cnt--;
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}

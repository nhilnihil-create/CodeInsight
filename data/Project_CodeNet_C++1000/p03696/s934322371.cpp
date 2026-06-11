#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={0,1,0,-1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*----------------------------------------------*/

signed main(){
  int n;
  cin>>n;
  string s;
  cin>>s;

  int l=0,r=0;
  rep(i,n){
    if(s[i]=='('){
      r++;
    }else{
      if(r==0) l++;
      else r--;
    }
  }

  // vi d(n,0);
  // int x=INF;
  // rep(i,n){
  //   if(i==0) d[i]=(s[i]=='('?1:-1);
  //   else d[i]=d[i-1]+(s[i]=='('?1:-1);
  //   chmin(x,d[i]);
  // }
  // cout<<x<<endl;
  string res="";
  rep(i,l) res+='(';
  res+=s;
  rep(i,r) res+=')';
  cout<<res<<endl;

  return 0;
}

#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(13)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;
//ll longinf=1ll<<60;
int inf=1<<29;
int dn[4]={-1,1,0,0};
int dm[4]={0,0,-1,1};
ll longinf=(1ll<<60);
char w[1001][1001];

int main(){
      ll x,y;
      cin>>x>>y;
      if(abs(x-y)<=1) cout<<"Brown"<<endl;
      else{
            cout<<"Alice"<<endl;
      }
      return 0;
}
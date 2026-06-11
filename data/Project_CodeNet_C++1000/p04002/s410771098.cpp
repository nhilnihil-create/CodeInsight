#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#define FI first
#define SE second
#define PF push_front
#define PB push_back
#define PPF pop_front
#define PPB pop_back
#define MA make_pair
#define ll long long
#define PA pair<int,int>
#define VE vector<int>
#define VP vector<PA>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int INF=1e9+7;
const int mod=1e9+7;
//
struct poi{
  int X;int Y;int Z;
  bool operator<(const poi&R)const{
    return X==R.X ? Y==R.Y ? Z<R.Z : Y<R.Y : X<R.X;
  }
};
/*
ll GCD(ll A,ll B){
  return (B==0)?(A):(GCD(B,A%B));
}
ll LCM(ll A,ll B){
  return A/GCD(A,B)*B;
}
*/
int main(){
  ll H,W,N;
  VP V;
  cin>>H>>W>>N;
  FOR(i,0,N){
    int A,B;
    cin>>A>>B;
    A--;B--;
    FOR(j,0,3){
      FOR(k,0,3){
        if(0<=(A-j)&&(A-j)<H-2&&0<=(B-k)&&(B-k)<W-2){
          V.PB(MA((A-j),(B-k)));
        }
      }
    }
  }
  sort(V.begin(),V.end());
  ll ans[10];
  fill(ans,ans+10,0);
  int now=0;
  while(now<(int)V.size()){
    int c=1;
    while(now<(int)V.size()-1&&V[now]==V[now+1]){
      now++;
      c++;
    }
    now++;
    ans[c]++;
  }
  ans[0]=(H-2)*(W-2);
  FOR(i,1,10){
    ans[0]-=ans[i];
  }
  FOR(i,0,10){
    cout<<ans[i]<<endl;
  }
	return 0;
}
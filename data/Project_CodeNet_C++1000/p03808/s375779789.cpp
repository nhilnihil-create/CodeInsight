#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef set<int> si;
typedef string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
ll N;
ll A[100010],B[100010];
int main(){
  bool f=true;
  cin>>N;
  ll sum=0;
  rep(i,N){
    cin>>A[i];
    sum+=A[i];
  }
  ll z=N*(N+1)/2,n;
  if(sum%z==0){
    n=sum/z;
  }
  else{
    f=false;
  }
  rep(i,N-1){
    B[i]=A[i+1]-A[i];
  }
  B[N-1]=A[0]-A[N-1];
  ll x=0;
  rep(i,N){
    if(n-B[i]>=0&&(n-B[i])%N==0){
      x+=(n-B[i])/N;
    }
    else{
      f=false;
      break;
    }
  }
  if(n==x&&f) prin("YES");
  else prin("NO");
  return 0;
}

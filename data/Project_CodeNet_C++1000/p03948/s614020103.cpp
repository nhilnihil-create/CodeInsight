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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) std::memset(arg,n,sizeof(arg))
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::set<int> si;
typedef std::string str;
const int INF=1e+9;
const ll INFLL=1e+17;
const ll MOD=1e+9+7;
int N,T;
int A[100010];
int main(){
  cin>>N>>T;
  rep(i,N) cin>>A[i];
  int max=0,min=INF,gap=0,cnt=1;
  for(int i=N-1;i>=0;i--){
    if(max<A[i]){
      max=A[i];
      min=A[i];
    }
    if(min>A[i]){
      min=A[i];
      if(gap<max-min){
	gap=max-min;
	cnt=1;
      }
      else if(gap!=0&&gap==max-min){
	cnt++;
      }
    }
  }
  prin(cnt);
  
  return 0;
}

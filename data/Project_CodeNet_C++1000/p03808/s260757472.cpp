#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()


int main(){
  int n;cin>>n;
  int a[n];rep(i,n)cin>>a[i];
  int b[n];rep(i,n-1)b[i]=a[i+1]-a[i];
  b[n-1]=a[0]-a[n-1];
  ll sum=0;
  rep(i,n)sum+=a[i];
  if(sum%(1ll*n*(n+1)/2)!=0){
    cout<<"NO"<<endl;exit(0);
  }
  int ctr=sum/(1ll*n*(n+1)/2);
  rep(i,n)b[i]-=ctr;
  rep(i,n){
    if(b[i]<=0&&(-b[i])%n==0)continue;
    else{
      cout<<"NO"<<endl;exit(0);
    }
  }
  cout<<"YES"<<endl;
}
  
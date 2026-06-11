#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
int gcd(int A,int B){
  if(A<B)
    swap(A,B);
  while(1){
    if(A%B==0)
      return B;
    int C=A%B;
    A=B;
    B=C;
  }
}
int minX(int A,int B){
  int C=gcd(A,B);
  return A*B/C;
}
signed main(){
  int N;
  cin>>N;
  int T,A;
  cin>>T>>A;
  int ans=T+A;
  rep(i,1,N){
    int t,a;
    cin>>t>>a;
    if(T<=t&&A<=a){
      T=t;
      A=a;
    }
    else{
      int TK=(T+t-1)/t,AK=(A+a-1)/a;
      T=t*max(TK,AK);
      A=a*max(TK,AK);
    }
  }
  ans=T+A;
  cout<<ans<<endl;
  }


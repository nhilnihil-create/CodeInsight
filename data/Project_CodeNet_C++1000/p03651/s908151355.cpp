#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(25) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 5100000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
lli gcd(lli num1, lli num2){
    return num2 != 0 ? gcd(num2, num1 % num2) : num1;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,F,N,M,K,L,R,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> N >> K;
  Vec(P,lli,N,0);
  rep(i,0,N)cin >> P[i];
  sum=P[0];
  num=P[0];
  rep(i,1,N){
    chmax(num,P[i]);
    sum=gcd(sum,P[i]);
  }
  if(K>num||K%sum)Out("IMPOSSIBLE");
  else Out("POSSIBLE");
}
  
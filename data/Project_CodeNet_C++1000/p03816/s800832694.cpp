#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 99999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(150) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 5100000
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
  lli A,B,C,D,E,F,N,M,K,L,R,X,Y,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> N;
  map<int,int>P;
  rep(i,0,N){
    cin >> A;
    P[A]++;
  }
  if(P.size()%2==0)flag=-1;
  Out(P.size()+flag);
}
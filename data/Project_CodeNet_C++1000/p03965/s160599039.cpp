#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 99999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m;i>n;i--)
#define pb(n) push_back(n)
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(20) << S << endl
#define Vecpr(K,L1,L2,N) vector<pair<L1,L2>> K(N)
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,R) vector<vector<L>> K(N, vector<L>(M,R))
#define mod 1000000007
#define MAX 510000
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a)
int main(){
  lli A=INF,B=0,C=INF,D=INF,E,F,N,M,K,sum=0,num=0,cnt=1,next=0;
  string S;cin>>S;
  A=S.size();
  rep(i,0,A)if(S[i]=='p')B++;
  Out(A/2-B);
}

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
signed main(){
  int N;
  cin>>N;
  vector<bool> A(100000);
  int count=0;
  rep(i,0,N){
    int X; cin>>X;
    if(A[X-1])
      count++;
    else
      A[X-1]=1;
    }
  int K=(count+1)/2;
  cout<<N-K*2<<endl;
  }

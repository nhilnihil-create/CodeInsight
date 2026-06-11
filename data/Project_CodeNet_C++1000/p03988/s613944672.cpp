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
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
void fin(){cout<<"Impossible"<<endl;}
signed main(){
  int N; cin>>N;
  vi A(N);
  rep(i,0,N) cin>>A[i];
  sort(ALL(A),greater<int>());
  if(A[0]!=A[1]){
    fin();
    return 0;
  }
  vi B(N);
  rep(i,0,N) B[A[i]]++;
  int mem=(A[0]+1)/2;
  rep(i,0,mem){
    if(B[i]>0){
      fin();
      return 0;
    }
  }
  if(A[0]%2==0){
    if(B[mem]!=1){
      fin();
      return 0;
    }
  }
  else{
    if(B[mem]!=2){
      fin();
      return 0;
    }
  }
  rep(i,mem+1,A[0]){
    if(B[i]<2){
      fin();
      return 0;
    }
  }
  cout<<"Possible"<<endl;
  }


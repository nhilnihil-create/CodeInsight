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
signed main(){
  int N,H,W;
  cin>>H>>W>>N;
  vii A(H,vi(W));
  int h=0,w=0;
  REP(i,1,N){
    int X;
    cin>>X;
    rep(j,0,X){
      A[h][w]=i;
      if(h%2==0){
        w++;
        if(w==W){
          h++;
          w--;
        }
      }
      else{
        w--;
        if(w==-1){
          h++;
          w++;
        }
      }
    }
  }
  rep(i,0,H){
    rep(j,0,W) cout<<A[i][j]<<" ";
    cout<<endl;
  }
  }


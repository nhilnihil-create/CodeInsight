#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N;cin>>N;
    int pcost=0;
    int mcost=0;
    vector<int>vec(N);
    REP(i,N) cin>>vec[i];
    vector<int>S(N,0);
  	vector<int>Sc(N,0);
    S[0]=vec[0];
  	Sc=S;
    REP(i,N){
      	if(i%2==0&&S[i]<=0){
            int d=1-S[i];
            pcost+=d;	
            if(i!=N-1) S[i+1]=S[i]+vec[i+1]+d;
     		continue;
        }
        if(i%2==1&&S[i]>=0){
            int d=S[i]+1;
            pcost+=d;
            if(i!=N-1) S[i+1]=S[i]+vec[i+1]-d;
          continue;
        }
      	if(i!=N-1) S[i+1]=S[i]+vec[i+1];
    }
  	REP(i,N){
       if(i%2==0&&Sc[i]>=0){
            int d=1+Sc[i];
            mcost+=d;
            if(i!=N-1) Sc[i+1]=Sc[i]+vec[i+1]-d;
          continue;
        }
        if(i%2==1&&Sc[i]<=0){
            int d=1-Sc[i];
            mcost+=d;
            if(i!=N-1) Sc[i+1]=Sc[i]+vec[i+1]+d;
          continue;
        }
      	if(i!=N-1) Sc[i+1]=Sc[i]+vec[i+1];
    }
  	cout<<min(mcost,pcost)<<endl;
}

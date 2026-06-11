#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
const int INF=1e15;
const int MOD=1e13+7;

int C[51][51];

void com_table(int N){
    REP(i,N+1){
        REP(j,i+1){
            if(j==0||j==i)C[i][j]=1;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j]);
        }
    }
}

signed main(){
    int N,A,B;cin>>N>>A>>B;
    com_table(N);
    vector<int>V(N);
    REP(i,N)cin>>V[i];
    sort(V.rbegin(),V.rend());
    double maxave=0;
    int stop=0;
    for(int i=A;i<=B;i++){
        double d=0;
        REP(j,i)d+=V[j];
        d/=i;
        maxave=max(d,maxave);
    }
  	cout<<setprecision(20.10);
  	cout<<maxave<<endl;
    map<int,int>memo;
    int count=0;
  	int z=0;
  	int v=0;
    REP(i,A){
        if(V[A-1]==V[i]){
            z++;
            v++;
        }
    }
    for(int i=A;i<N;i++){
        if(V[i]==V[A-1])v++;
    }
  	if(z!=A){
          int ans=C[v][z];
      	  cout<<setprecision(20.10);
          cout<<ans<<endl;
    }
  	else{
        int ans=0;
        for(int i=A;i<=B;i++){
            ans+=C[v][i];
        }
      	cout<<setprecision(20.10);
      	cout<<ans<<endl;
    }  	
}
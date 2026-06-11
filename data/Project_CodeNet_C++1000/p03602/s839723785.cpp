#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
 
typedef long long ll;
typedef pair<int,int> P;
ll longinf=1ll<<60;
int inf=1<<29;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int cost[300][300];
int mincost[300];
bool used[300];
int V;


int N;
ll A[300][300];
ll B[300][300];
ll C[300][300];
int main (){
      cin>>N;
      rep0(i,N)rep0(j,N) cin>>A[i][j];
      rep0(i,N)rep0(j,N) B[i][j]=A[i][j];
      rep0(k,N)rep0(i,N)rep0(j,N) B[i][j]=min(B[i][j],B[i][k]+B[k][j]);
      ll ans=0;
      rep0(i,N)rep0(j,N){
            if(A[i][j]>B[i][j]){
                  cout<<-1<<endl;
                  return 0;
            }
      }
      rep0(i,N)rep0(j,N) C[i][j]=0;
      rep0(k,N)rep0(i,N)rep0(j,N){
            if(B[i][j]==B[i][k]+B[k][j]&&k!=i&&k!=j){
                  C[i][j]=B[i][j];
            }
      }
      rep0(i,N)rep0(j,N){
            ans=ans+B[i][j]-C[i][j];
      }
      ans/=2;
      cout<<ans<<endl;
      
      return 0;
}

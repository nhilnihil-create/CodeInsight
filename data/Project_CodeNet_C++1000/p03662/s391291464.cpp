#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FOOR(i,a,b) for(int i=a;i<=b;i++)
#define FI first
#define SE second
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PB push_back
#define PQ priority_queue<int>
#define PGQ priority_queue<int,vector<int>,greater<int> >
#define VE vector<int>
#define VP vector<PA>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define MOD 1000000007
#define INF 1000000007
using namespace std;
//
int N;
VE A[100001];
int D[100001];
int DD[100001];
bool F[100001];
bool FF[100001];
int main(){
  cin>>N;
  FOR(i,0,N-1){
    int a,b;
    cin>>a>>b;
    A[a].PB(b);
    A[b].PB(a);
  }
  queue<int> que;
  que.push(1);
  while(que.size()){
    int x=que.front();
    que.pop();
    FOR(i,0,(int)A[x].size()){
      if(!F[A[x][i]]){
        D[A[x][i]]=D[x]+1;
        F[A[x][i]]=true;
        que.push(A[x][i]);
      }
    }
  }
  que.push(N);
  while(que.size()){
    int x=que.front();
    que.pop();
    FOR(i,0,(int)A[x].size()){
      if(!FF[A[x][i]]){
        DD[A[x][i]]=DD[x]+1;
        FF[A[x][i]]=true;
        que.push(A[x][i]);
      }
    }
  }
  int FE=0,SU=0;
  FOR(i,1,N+1){
    (D[i]<=DD[i]?FE++:SU++);
  }
  cout<<(FE>SU?"Fennec":"Snuke")<<endl;
  return 0;
}

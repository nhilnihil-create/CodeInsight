#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
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
int main(){
  long long N,M;
  long long X[100001],Y[100001];
  cin>>N>>M;
  FOR(i,1,N+1){
    cin>>X[i];
  }
  FOR(i,1,M+1){
    cin>>Y[i];
  }
  sort(X+1,X+N+1);
  sort(Y+1,Y+M+1);
  long long sumx=0,sumy=0;
  FOR(i,1,N+1){
    (sumx+=(i-1)*X[i]-(N-i)*X[i])%=MOD;
  }
  FOR(i,1,M+1){
    (sumy+=(i-1)*Y[i]-(M-i)*Y[i])%=MOD;
  }
  cout<<sumx*sumy%MOD<<endl;
  return 0;
}

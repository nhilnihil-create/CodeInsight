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
  int N,T,A[100000],B[100000];
  cin>>N>>T;
  FOR(i,0,N){
    cin>>A[i];
  }
  int MAX=-1;
  ROF(i,0,N){
    if(MAX<A[i]){
      MAX=A[i];
    }
    B[i]=MAX;
  }
  MAX=-1;
  int ans=0;
  FOR(i,0,N){
    if(B[i]-A[i]>MAX){
      MAX=B[i]-A[i];
      ans=1;
    }else if(B[i]-A[i]==MAX){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}

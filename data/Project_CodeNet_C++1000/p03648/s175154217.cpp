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
  long long K;
  long long A[50];
  cin>>K;
  FOR(i,0,K%50){
    A[i]=50-K%50+1+i;
  }
  FOR(i,K%50,50){
    A[i]=i-K%50;
  }
  cout<<50<<endl;
  FOR(i,0,50){
    if(i){
      cout<<" ";
    }
    cout<<A[i]+K/50;
  }
  cout<<endl;
  return 0;
}

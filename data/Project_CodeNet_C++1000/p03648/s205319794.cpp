#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#define FOR(i,a,b) for(int i=a;i<b;i++)
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
#define PI 3.14159265358979323846
using namespace std;
//
int main(){
  long long K;
  long long A[50];
  cin>>K;
  cout<<50<<endl;
  long long M=K/50;
  long long N=K%50;
  FOR(i,N,50){
    A[i]=M;
    M++;
  }
  M++;
  FOR(i,0,N){
    A[i]=M;
    M++;
  }
  FOR(i,0,50){
    if(i){
      cout<<" ";
    }
    cout<<A[i];
  }
  cout<<endl;
  return 0;
}

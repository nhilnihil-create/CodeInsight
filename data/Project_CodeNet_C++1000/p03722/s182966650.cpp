#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define df 0
typedef long int li;
const li INF=1e15;
struct edge{
  int u;
  int v;
  li c;
};

int main(){
  if(df) printf("*debug mode*\n");
  int n,m; cin >>n >>m;
  edge graph[m];
  for(edge& x: graph){
    cin >>x.u >>x.v >>x.c;
    x.u--; x.v--;
  }

  li road[n];
  road[0]=0;
  for(int i=1; i<n; i++) road[i]=-INF;
  for(int i=0;i<2*n;i++){
    for(edge& x: graph){
      if(road[x.v]<road[x.u]+x.c){
	road[x.v]=road[x.u]+x.c;
	if(i>=n)road[x.v]=INF;
      }
    }
  }
  if(road[n-1]==INF)printf("inf\n");
  else printf("%ld\n",road[n-1]);
}

/// confirm df==0 ///

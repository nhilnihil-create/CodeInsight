#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int N;
  cin>>N;
  int p[N];
  REP(i,N){
    int k;
    cin>>k;
    k--;
    p[k]=i;
  }
  int A[N],B[N];
  int X=N+1;
  REP(i,N)A[i]=X*(i+1);
  REP(i,N)B[i]=X*(N-i)+p[i];
  REP(i,N)cout<<A[i]<<" ";
  cout<<endl;
  REP(i,N)cout<<B[i]<<" ";
  cout<<endl;
  return 0;
}

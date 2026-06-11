#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector< vector<int> > VVI;
typedef vector< vector<int> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair

int main(){
  int N;
  cin>>N;
  VL P(N);
  rep(i,N) cin>>P[i];
  VL A(N),B(N);
  VL Q(N);
  rep(i,N) Q[P[i]-1]=i+1;
  rep(i,N) A[i]=Q[i]+30000*i;
  rep(i,N) B[i]=30000*(N-i);
  rep(i,N){
    if(i) cout<<" ";
    cout<<A[i];
  }
  cout<<endl;
  rep(i,N){
    if(i) cout<<" ";
    cout<<B[i];
  }
  cout<<endl;
}
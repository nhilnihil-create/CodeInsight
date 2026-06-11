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
  VI A(N);
  rep(i,N) cin>>A[i];
  sort(all(A));
  int ans=1;
  if(A[N-1]-A[0]>1) ans=0;
  else if(A[N-1]==A[0]){
    if(N<A[0]*2&&N-1!=A[0]) ans=0;
  }else{
    int X=A.end()-lower_bound(all(A),A[N-1]);
    ans=0;
    if(X>=2*(A[N-1]-N+X)&&N-X<A[N-1]) ans=1;
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
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
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int N;
  cin>>N;
  VI A(N);
  rep(i,N) cin>>A[i];
  ll sum=0;
  ll ans=0;
  rep(i,N){
    if(A[i]) sum+=A[i];
    else{
      ans+=sum/2;
      sum=0;
    }
  }
  ans+=sum/2;
  cout<<ans<<endl;
}
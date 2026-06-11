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
  int K,T;
  cin>>K>>T;
  VI A(T);
  rep(i,T) cin>>A[i];
  sort(all(A));
  cout<<max(0,A[T-1]*2-K-1)<<endl;
}
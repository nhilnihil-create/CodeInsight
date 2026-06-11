#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,N) cin>>A[i];
  sort(A.begin(),A.end());

  if(A[0]+1<A.back()){
    cout<<"No"<<endl;
    return 0;
  }else if(A[0]==A.back()){
    if(A[0]==N-1||A[0]<=N/2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
  }

  int ind=0;
  for(int i=0;i<N;i++){
    if(A[i]!=A.back()) ind++;
  }

  int rest=N-ind;
  if(rest==1){
    cout<<"No"<<endl;
    return 0;
  }

  if(ind+1<=A.back()&&A.back()<=ind+rest/2) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}

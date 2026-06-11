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
  int N,M,K;
  cin>>N>>M>>K;
  int ans=0;
  rep(i,N+1) rep(j,M+1){
    if((N-i)*j+(M-j)*i==K) ans=1;
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int N,A,B;
  cin>>N>>A>>B;
  vector<ll> V(N);
  rep(i,N) cin>>V[i];
  sort(all(V));
  ll sum=0;
  rep(i,A) sum+=V[N-1-i];
  double ans=(double)sum/A;
  int U=upper_bound(all(V),V[N-A])-V.begin()-1,L=lower_bound(all(V),V[N-A])-V.begin();
  int S=U-(N-A)+1;
  ll COM[51][51];
  rep(i,51){
    COM[i][0]=1;
    COM[i][i]=1;
  }
  rep(i,51) rep(j,51) if(i&&j&&i>j) COM[i][j]=COM[i-1][j-1]+COM[i-1][j];
  ll C=COM[U-L+1][S];
  if(V[N-A]==V[N-1]) rep(i,min(N-A-L,B-A)) C+=COM[U-L+1][S+i+1];
  cout.precision(10);
  cout<<ans<<endl;
  cout<<C<<endl;
}



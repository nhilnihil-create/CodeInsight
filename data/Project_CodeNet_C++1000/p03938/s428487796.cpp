#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  ll C[N];
  ll p;
  for(int i=0;i<N;++i){
    cin>>p;
    p--;
    C[p] = i;
  }
  ll A[N];
  ll B[N];
  A[0] = 1;
  B[0] = C[0] - A[0];
  for(int i=1;i<N;++i){
    if(C[i]>C[i-1]){
      A[i] = A[i-1] + (C[i] - C[i-1]) + 1;
      B[i] = B[i-1] - 1;
    }
    else{
      A[i] = A[i-1] + 1;
      B[i] = B[i-1] + (C[i] - C[i-1]) - 1;
    }
  }
  ll minB = B[N-1];
  if(minB<=0){
    minB = -minB;
    for(int i=0;i<N;++i){
      B[i] += minB + 1;
    }
  }
  for(int i=0;i<N;++i){
    cout<<A[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<N;++i){
    cout<<B[i]<<" ";
  }
  cout<<endl;
}

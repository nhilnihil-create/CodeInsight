#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265358979
#define MOD 998244353
const int MAX = 510000;

int main() {
  ll N,L;
  cin>>N>>L;
  vector<ll>a(N);
  vector<ll>dif(N-1);
  rep(i,N){cin>>a[i];}
  int flag=0;
  rep(i,N-1){dif[i]=a[i]+a[i+1];if(dif[i]>=L){flag=i+N+1;}}
  if(flag==0){cout<<"Impossible";}
  else{
    cout<<"Possible"<<endl;
  	flag-=N;
  	for(int i=1;i<flag;i++){cout<<i<<endl;}
  	for(int i=N-1;i>flag;i--){cout<<i<<endl;}
    cout<<flag;
  }
}
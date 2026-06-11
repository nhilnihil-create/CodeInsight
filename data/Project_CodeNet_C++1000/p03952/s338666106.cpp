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
  ll N,x;
  cin>>N>>x;
  vector<ll>a(2*N-1);
  if(x==1||x==(2*N-1)){cout<<"No";return 0;}
  if(N==2){cout<<"Yes"<<endl<<1<<endl<<2<<endl<<3;return 0;}
  if(x==2||x==(2*N-2)){
    a[N-2]=x-1;
    a[N-1]=x;
    a[N]=x+1;
    ll b=2*N-1;
    int p=1;
    if(x==2){p=4;}
    for(int i=0;i<b;i++){
      if(i==N-2||i==N-1||i==N){continue;}
      a[i]=p;
      p++;
    }
    cout<<"Yes"<<endl;
    rep(i,b){cout<<a[i]<<endl;} 
    return 0;
  }
    a[N-3]=x+2;
    a[N-2]=x-1;
    a[N-1]=x;
    a[N]=x+1;
    a[N+1]=x-2;
    ll b=2*N-1;
    int p=1;
    for(int i=0;i<b;i++){
      if(i==N-3||i==N-2||i==N-1||i==N||i==N+1){continue;}
      if(p==x-2){p=x+3;}
      a[i]=p;
      p++;
    }
    cout<<"Yes"<<endl;
    rep(i,b){cout<<a[i]<<endl;}
}
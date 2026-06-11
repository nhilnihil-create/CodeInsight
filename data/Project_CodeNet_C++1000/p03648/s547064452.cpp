#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define fi first
#define se second
#define int long long
//template

//main
signed main(){
  int K;cin>>K;
  if(K<1000){
    Cout(2);
    int a=K/2+1,b=K/2+1;
    if(K%2){a++;b--;}
    cout<<a<<" "<<b<<endl;
  }
  else{
    Cout(50);
    std::vector<int> v(50,K/50);
    for(int i=0;i<50;i++)v[i]+=i;
    for(int i=0;i<K%50;i++){
      for(int j=0;j<50;j++){
        if(j==i)v[j]+=50;
        else v[j]--;
      }
    }
    for(int i=0;i<50;i++){
      if(i)cout<<" ";
      cout<<v[i];
    }
    cout<<endl;
  }
}

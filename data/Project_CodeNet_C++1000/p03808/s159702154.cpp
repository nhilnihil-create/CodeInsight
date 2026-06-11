#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#define MOD 1000000007

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline T gcd(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<class T> inline T lcm(T a,T b){return a*b/gcd(a,b);}

const int INF=1e9;
const double eps=0.0000000001;


int main(){
  ll n;
  cin >> n;
  ll sum=0,v=(1+n)*n/2,a[1000000];
  FOR(i,n){
    cin >> a[i];
    sum+=a[i];
  }

  if(sum%v!=0){
    cout << "NO" << endl;
    return 0;
  }
  ll kaisuu=sum/v,m=0;

  ll b[1000000],sumi=0;
  bool c=0;
  FOR(i,n){
    if(i==n-1)b[i]=a[0]-a[i];
    else b[i]=a[i+1]-a[i];

    if((b[i]-kaisuu)%(n)!=0){
      c=1;
    }else{
      m+=abs((b[i]-kaisuu)/n);
    }
  }
  if(m!=kaisuu){
    c=1;
  }

  if(c){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }

  

  

  
  
  
  
}

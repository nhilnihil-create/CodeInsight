#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, n) ;for (int i = 0;i < (int)(n);i++)
#define rep2(i, s, n) ;for (int i = s; i < (int)(n);i++)
#define ALL(vec)  (vec).begin(),(vec).end()
#define pi 3.1415926535897932384626433832795
#define MAX_INF 9223372036854775807
#define MIN_INF (922337203685477587+1)
#define sosuu 1000000007

lli combi[55][55];

lli nCr(lli n, lli r)
{
       if(n<r) return 0;
       if(n==r) return combi[n][r] = 1;
       if(r==0) return combi[n][r] = 1;
       if(r==1) return combi[n][r] = n;
       if(combi[n][r]) return combi[n][r];
       return combi[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int main() {
  lli N;
  cin >> N;
  lli ocount=0, count=0;
  
  int P;
  cin >> P;
  lli a;
  rep(i, N){
  cin>>a;
    if(a%2==0) ocount++;
    else count ++;
  }
  
  lli ans=0;
  
  if(P==0){
  rep(i, count/2+1){
  ans+=nCr(count,2*i);
  }
    rep(j, ocount){ans*=2;}
  }
  if(P==1){
  rep(i, (count+1)/2){
  ans+=nCr(count,2*i+1);
  }
    rep(j, ocount){ans*=2;}
  }
  cout <<ans << endl;
}
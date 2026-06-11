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




int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N),B(M);
  rep(i, N)  cin >> A[i];
  rep(i, M)  cin >> B[i];
  
  rep(i,N-M+1){rep(j,N-M+1){
    
  bool a=true;
   
    rep(q,B.size()){rep(p,B.size()){
  if(A[q+j].at(p+i)!=B[q].at(p))
    a=false;
      }}
    
  if(a==true){cout <<"Yes"<<endl;
             return 0;
            } 
    }}
  cout << "No"<<endl;
}
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 


int main(){
  string A, B, C;
  cin >> A >> B >> C;
  
  if(  (A.at(A.size() - 1) == B.at(0)) && \
       (B.at(B.size() - 1) == C.at(0))  ){
    cout << "YES";
  }else{
    cout << "NO";
  }
}
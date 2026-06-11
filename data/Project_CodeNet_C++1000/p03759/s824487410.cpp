#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 



int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  if(b-a == c-b){
    cout << "YES";
  }else{
    cout << "NO";
  }
}
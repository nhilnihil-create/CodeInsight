#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
 
int main()
{
  string A, B;
  cin >> A >> B;

  if(A.size()>B.size()){
    cout << "GREATER" <<endl;
  }else if(A.size()<B.size()){
    cout << "LESS" << endl;
  }else{
    if(A>B){
      cout << "GREATER" << endl;
    }else if(A<B){
      cout << "LESS" << endl;
    }else{
      cout << "EQUAL" << endl;
    }
  }
}
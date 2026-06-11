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
  string S;
  cin >> S;

  int n = 0,s = 0,w = 0,e = 0;
  REP(i,S.size()){
    if(S.at(i) == 'N'){
      n++;
    }
  }
  REP(i,S.size()){
    if(S.at(i) == 'S'){
      s++;
    }
  }
  REP(i,S.size()){
    if(S.at(i) == 'W'){
      w++;
    }
  }
  REP(i,S.size()){
    if(S.at(i) == 'E'){
      e++;
    }
  }

  if((n!=0&&s==0)||(n==0&&s!=0)){
    cout << "No" << endl;
  }else if((e!=0&&w==0)||(e==0&&w!=0)){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}
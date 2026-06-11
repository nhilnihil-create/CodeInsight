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
  string O, E;
  cin >> O >> E;

  string a = "";
  REP(i,O.size()+E.size()){
    if(i%2 == 0){
      a.push_back(O.at(i/2));
    }else{
      a.push_back(E.at((i-1)/2));
    }
  }

  cout << a << endl;
}
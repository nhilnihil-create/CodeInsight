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
  ll a, b;
  cin >> a >> b;

  if(a>0&&b>0){
    cout << "Positive" << endl;
  }else if(a<=0&&b>=0){
    cout << "Zero" << endl;
  }else if(a<0&&b<0&&(b-a)%2==0){
    cout << "Negative" << endl;
  }else{
    cout << "Positive" << endl;
  }
}
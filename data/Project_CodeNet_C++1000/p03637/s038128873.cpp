#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  int N;
  cin >> N;
  int odd=0;
  int four=0;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
    if(A[i]%2==1){
      odd++;
    }else if(A[i]%4==0){
      four++;
    }
  }

  if(odd-1<=four){
    if(odd<=four){
      cout << "Yes" << endl;
    }else{
      if(odd+four==N){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }else{
    cout << "No" << endl;
  }
  
  
}
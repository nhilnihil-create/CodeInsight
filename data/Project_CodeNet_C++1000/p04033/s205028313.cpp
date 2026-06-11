#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll a,b;
  cin>>a>>b;
  if(a>0 && b>0){
    cout << "Positive" << endl;
    return 0;
  }
  if(a < 0 && b < 0){
    if(((b-a)+1) % 2== 0){
      cout << "Positive" << endl;
      return 0;
    }
    else{
      cout << "Negative" << endl;
      return 0;
    }
  }
  if(a <= 0 && 0 <= b){
    cout << "Zero" << endl;
    return 0;
  }
}
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
  string a,b;
  cin >> a >> b;
  
  if(a.length() > b.length()){
    cout << "GREATER" << endl;
    return 0;
  }
  else if(a.length() < b.length()){
    cout << "LESS" << endl;
    return 0;
  }
  else if(a == b){
    cout << "EQUAL" << endl;
    return 0;
  } 
  else{
    rep(i,a.length()){
      if((int)a[i] >(int)b[i]){
        cout << "GREATER" << endl;
        return 0;
      }else if ((int)a[i] < (int)b[i]){
        cout << "LESS" << endl;
        return 0;
      }
    }
  }
}

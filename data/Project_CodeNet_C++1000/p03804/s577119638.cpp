#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define IINF 2e9
#define MOD 1e9+7

#define loop(i, n) for(int i = 0;i < n;i++)
#define vi vector<int>
#define vvi vector<vi>

int main(void){
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, m) cin >> b[i];
  
  if(n == m){
    bool ok = true;
    loop(i, n){
      loop(j, m){
        if(a[i][j] != b[i][j]) ok = false;
      }
    }
    
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }
  
  loop(i, n-m){
    loop(j, n-m){
      bool ok = true;
      loop(k, m){
        loop(l, m){
          if(a[i+k][j+l] != b[k][l]) ok = false;
        }
      }
      if(ok){
        cout << "Yes" << endl;
        return 0;
      }
    }
  } 

  cout << "No" << endl;
}

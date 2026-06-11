#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, m;
  cin >> n >> m;
  int a[m+1], b[m+1];
  for(int i=1; i<=m; ++i) cin >> a[i] >> b[i];
  
  int num[n+1] = {};
  for(int i=1; i<=m; ++i){
    num[a[i]]++;
    num[b[i]]++;
  }

  for(int i=1; i<=n; ++i) cout << num[i] << endl;
  return 0;
}
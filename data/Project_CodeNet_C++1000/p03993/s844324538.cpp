#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  int mx = 0;
  for(int i=1; i<=n; ++i){
    cin >> a[i];
  }

  int cnt = 0;
  for(int i=1; i<=n; ++i){
    if(a[a[i]]==i) cnt++;
  }
  cout << cnt/2 << endl;
}
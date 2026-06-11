#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  vector<int> a(3);
  for(int i=0; i<3; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  if(a[0]%2 == 0 || a[1]%2 == 0 || a[2]%2 == 0) cout << 0 << endl;
  else{
    cout << (ll)a[0]*a[1];
  }
  return 0;
}